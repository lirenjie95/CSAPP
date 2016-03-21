#include <stdio.h>
#define INT_MAX 0x7FFFFFFF
#define INT_MIN 0x80000000
int saturating_add(int x, int y)
{
	int w,t,ans,plus,minus,nop;
	w = sizeof(int)<<3;
	t = x + y;
	ans = x + y;
	x>>=(w-1);
	y>>=(w-1);
	t>>=(w-1);
	plus = ~x&~y&t;
	minus = x&y&~t;
	nop = ~(plus|minus);
	return (plus & INT_MAX)|(nop & ans)|(minus & INT_MIN);
}
int main()
{
	int x,y;
	scanf("%x %x",&x,&y);
	printf("%x\n",saturating_add(x,y));
	return 0;
}