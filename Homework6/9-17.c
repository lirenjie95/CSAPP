static void *find_fit(size_t asize)
{
	char *oldrover;
	oldrover = rover;
	/* search from the rover to the end of list */
	for ( ; GET_SIZE(HDRP(rover)) > 0; rover = NEXT_BLKP(rover))
		if (!GET_ALLOC(HDRP(rover)) && (asize <= GET_SIZE(HDRP(rover))))
			return rover;
	/* search from start of list to old rover */
	for (rover = heap_listp; rover < oldrover; rover = NEXT_BLKP(rover))
		if (!GET_ALLOC(HDRP(rover)) && (asize <= GET_SIZE(HDRP(rover))))
			return rover;
	return NULL; /* no fit found */
}
static void *coalesce(void *bp)
{
	int prev_alloc = GET_ALLOC(FTRP(PREV_BLKP(bp)));
	int next_alloc = GET_ALLOC(HDRP(NEXT_BLKP(bp)));
	size_t size = GET_SIZE(HDRP(bp));
	if (prev_alloc && next_alloc) { /* Case 1 */
		return bp;
	}
	else if (prev_alloc && !next_alloc) { /* Case 2 */
		size += GET_SIZE(HDRP(NEXT_BLKP(bp)));
		PUT(HDRP(bp), PACK(size, 0));
		PUT(FTRP(bp), PACK(size,0));
	}
	else if (!prev_alloc && next_alloc) { /* Case 3 */
		size += GET_SIZE(HDRP(PREV_BLKP(bp)));
		PUT(FTRP(bp), PACK(size, 0));
		PUT(HDRP(PREV_BLKP(bp)), PACK(size, 0));
		bp = PREV_BLKP(bp);
	}
	else { /* Case 4 */
		size += GET_SIZE(HDRP(PREV_BLKP(bp)))+GET_SIZE(FTRP(NEXT_BLKP(bp)));
		PUT(HDRP(PREV_BLKP(bp)), PACK(size, 0));
		PUT(FTRP(NEXT_BLKP(bp)), PACK(size, 0));
		bp = PREV_BLKP(bp);
	}
	/* Make sure the rover isn¡¯t pointing into the free block */
	/* that we just coalesced */
	if ((rover > (char *)bp) && (rover < NEXT_BLKP(bp)))
		rover = bp;
	return bp;
}
