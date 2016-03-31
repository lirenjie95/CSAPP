int test(int x, int y) {
	int val = 4*x;
	if (y > 0) {
		if (x < y)
			val = x-y;
		else
			val = x^y;
	}else if (y < -2)
		val = x+y;
	return val;
}