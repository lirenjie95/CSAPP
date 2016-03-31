void fix_set_diag_opt(fix_matrix A, int val) {
	int *Abase = &A[0][0];
	int index = 0;
	do {
		Abase[index] = val;
		index += (N+1);
	} while (index != (N+1)*N);
}
/*
A at %ebp+8, val at %ebp+12
1 movl 8(%ebp), %ecx Get Abase = &A[0][0]
2 movl 12(%ebp), %edx Get val
3 movl $0, %eax Set index4 to 0
4 .L14: loop:
5 movl %edx, (%ecx,%eax) Set Abase[index4/4] to val
6 addl $68, %eax index4 += 4(N+1)
7 cmpl $1088, %eax Compare index4:4N(N+1)
8 jne .L14 If !=, goto loop
*/