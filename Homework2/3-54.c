int decode2(int x, int y, int z)
{
	int result;
	z -= y;
	result = z;
	result <<= 15;
	result >>= 15;
	result *= x^z;
	return result;
}