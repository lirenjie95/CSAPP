void *memset(void *s, int c, size_t n)
{
    unsigned int K = sizeof(unsigned long);
    unsigned char *schar = (unsigned char*)s;
    unsigned long *lchar;
    unsigned long fill = 0;
    int i = 0;
    for(i = 0; i < K; i++)
        fill += (c&0xff) << (i<<3);
    while((unsigned)schar%K && n)
    {
        *schar++ = (unsigned char)c;
        n--;
    }
    lchar = (unsigned long*) schar;
    while ( n >= K ) {
        *lchar++ = fill;
        n -= K;
    }
    schar = (unsigned char*) lchar;
    while(n)
    {
        *schar++ = (unsigned char)c;
        --n;
    }
    return s;
}