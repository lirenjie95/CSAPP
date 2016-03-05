/*
 * Generate mask indicating leftmost 1 in x.  Assume w=32.
 * For example, 0xFF00 -> 0x8000, and 0x6000 -> 0x4000.
 * If x = 0, then return 0.
 */
#include <stdio.h>
int leftmost_one(unsigned x)
{
	x |= x >> 1;
	x |= x >> 2;
	x |= x >> 4;
	x |= x >> 8;
	x |= x >> 16;
	return x - (x >> 1);
}
int main()
{
	unsigned x;
	printf("Please input x: ");
	scanf("%x",&x);
	printf("leftmost_one(x)=0x%x\n",leftmost_one(x));
	return 0;
}