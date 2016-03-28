/*
A.
x:%esi
n:%ecx
result:%edi->%eax
mask:%edx
B. result=1431655765, mask=-2147483648
C. mask!=0
D. mask=((unsigned)mask)>>(0xFF&n)
E. result=result^(mask&x)
*/
int loop(int x, int n)
{
	int result = 1431655765;
	int mask;
	for (mask = 1<<31; mask != 0; mask = ((unsigned)mask)>>(0xFF&n)){
		result ^= mask&x;
	}
	return result;
}
