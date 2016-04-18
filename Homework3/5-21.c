void psum(float a[], float p[], long int n)
{
	long int n;
	float val = 0;
	float v0,v1;
	for(i = 1; i < n-1; i+=2)
	{
		v0 = a[i];
		v1 = a[i+1];
		v1 = v0+v1;
		p[i] = val+v0;
		p[i+1] = val+v1;
		val = val+v1;
	}
	for(; i < n; i++)
	{
		val = val+a[i];
		p[i] = val;
	}
}