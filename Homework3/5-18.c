void inner4(vec_ptr x, vec_ptr y, data_t *dest)
{
	long int i;
	int length = vec_length(x);
	data_t *xdata = get_vec_start(x);
	data_t *ydata = get_vec_start(y);
	data_t sum = (data_t) 0;
	data_t sum1,sum2,sum3;
	int limit = length-2;
	for (i = 0; i <limit; i += 3){
		sum1 = xdata[i]*ydata[i];
		sum2 = xdata[i+1]*ydata[i+1];
		sum3 = xdata[i+2]*ydata[i+2];
		sum = sum+(sum1+sum2+sum3);
	}
	for(; i < length; i++)
		sum = sum + xdata[i]*ydata[i];
	*dest = sum;
}