#include <stdio.h>
unsigned replace_byte (unsigned x, unsigned char b, int i)
{
	unsigned y,z;
	y = 0xFF<<(i<<3);
	y = ~y;
	z = b<<(i<<3);
	return x&y|z;
}
int main()
{
	unsigned A,B;
	A = replace_byte(0x12345678,0xAB,2);
	B = replace_byte(0x12345678,0xAB,0);
	printf("A=%x, B=%x.\n",A,B);
	return 0;
}