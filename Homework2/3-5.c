/*
1 movl 8(%ebp), %edi Get xp
2 movl 12(%ebp), %edx Get yp
3 movl 16(%ebp), %ecx Get zp
4 movl (%edx), %ebx Get y
5 movl (%ecx), %esi Get z
6 movl (%edi), %eax Get x
7 movl %eax, (%edx) Store x at yp
8 movl %ebx, (%ecx) Store y at zp
9 movl %esi, (%edi) Store z at xp
*/
void decode1(int *xp, int *yp, int *zp)
{
	int tx = *xp;
	int ty = *yp;
	int tz = *zp;
	*yp = tx;
	*zp = ty;
	*xp = tz;
}