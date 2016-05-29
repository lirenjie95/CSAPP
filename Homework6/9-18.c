int mm_init(void)
{
        /* Create the initial empty heap */
        heap_listp = mem_sbrk(2*WSIZE);
        if (heap_listp == (void *)-1)
                return -1;
        PUT(heap_listp + (0*WSIZE), PACK(WSIZE, 1)); /* Prologue header */
        PUT(heap_listp + (1*WSIZE), PACK(0, 3));     /* Epilogue header */
        heap_listp += WSIZE;

        /* Extend the empty heap with a free block of CHUNKSIZE bytes */
        if (extend_heap(CHUNKSIZE/WSIZE) == NULL)
                return -1;
        return 0;
}

static void *extend_heap(size_t words)
{
        char *bp;
        size_t size;

        /* Allocate an even number of words to maintain aligment */
        size = (words % 2) ? (words+1) * WSIZE : words * WSIZE;
        bp = mem_sbrk(size);
        if ((long)bp == -1)
                return NULL;

        /* Initialize free block header/footer and the epilogue header */
        int prev_alloc = GET_ALLOC_PREV(HDRP(bp));
        PUT(HDRP(bp), PACK(size, prev_alloc)); /* Free block header */
        PUT(FTRP(bp), PACK(size, prev_alloc)); /* Free block footer */
        PUT(HDRP(NEXT_BLKP(bp)), PACK(0, 1));  /* New epilogue header */

        /* Coalesce if the previous block was free */
        return coalesce(bp);
}

void mm_free(void *bp)
{
        size_t size;

        int prev_alloc = GET_ALLOC_PREV(HDRP(bp));
        size = GET_SIZE(HDRP(bp));
        PUT(HDRP(bp), PACK(size, prev_alloc));
        PUT(FTRP(bp), PACK(size, prev_alloc));

        char *next_block = NEXT_BLKP(bp);
        int next_alloc = GET_ALLOC(HDRP(next_block));
        size = GET_SIZE(HDRP(next_block));
        PUT(HDRP(next_block), PACK(size, next_alloc));
        if (!next_alloc)
                PUT(FTRP(next_block), PACK(size, next_alloc));

        coalesce(bp);
}

static void *coalesce(void *bp)
{
        size_t prev_alloc = GET_ALLOC_PREV(HDRP(bp));
        size_t next_alloc = GET_ALLOC(HDRP(NEXT_BLKP(bp)));
        size_t size = GET_SIZE(HDRP(bp));

        char *next_block;
        size_t next_size;

        if (prev_alloc && next_alloc)         /* Case 1 */
                return bp;

        else if (prev_alloc && !next_alloc) { /* Case 2 */
                size += GET_SIZE(HDRP(NEXT_BLKP(bp)));
                PUT(HDRP(bp), PACK(size, prev_alloc));
                PUT(FTRP(bp), PACK(size, prev_alloc));
        }

        else if (!prev_alloc && next_alloc) { /* Case 3 */
                bp = PREV_BLKP(bp);
                size += GET_SIZE(HDRP(bp));
                prev_alloc = GET_ALLOC_PREV(HDRP(bp));
                PUT(HDRP(bp), PACK(size, prev_alloc));
                PUT(FTRP(bp), PACK(size, prev_alloc));
        }

        else {                                /* Case 4 */
                size += GET_SIZE(HDRP(PREV_BLKP(bp))) + GET_SIZE(HDRP(NEXT_BLKP(bp)));
                bp = PREV_BLKP(bp);
                prev_alloc = GET_ALLOC_PREV(HDRP(bp));
                PUT(HDRP(bp), PACK(size, prev_alloc));
                PUT(FTRP(bp), PACK(size, prev_alloc));
        }
        return bp;
}

void *mm_malloc(size_t size)
{
        size_t asize;               /* Adjusted block size */
        size_t extendsize;          /* Amount to extend heap if no fit */
        char *bp;

        /* Ignore spurious requests */
        if (size == 0)
                return NULL;

        /* Adjust block size to include overhead and alignment reqs. */
        asize = DSIZE * ((size + (WSIZE) + (DSIZE-1)) / DSIZE);

        /* Search the free list for a fit */
        bp = find_fit(asize);

        /* No fit found. Get more memory and place the block */
        if (bp == NULL) {
                extendsize = MAX(asize, CHUNKSIZE);
                bp = extend_heap(extendsize/WSIZE);
                if (bp == NULL)
                        return NULL;
        }

        /* Here, we found a fit.  Just place info into it. */
        place(bp, asize);
        return bp;
}