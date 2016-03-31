//A.
int fun_a(unsigned x) {
	int val = 0;
	while (x) {
		val ^= x;
		x >>= 1;
	}
	return val & 0x1;
}
//B. It will return 1 if there is an odd number of ones in x and 0 if there is an even number.
