#include <stdio.h>
#define TMax 0x7FFFFFFF
#define TMin 0x80000000
int saturating_add(int x, int y)
{
	int Ans;
	Ans = x+y;
	if(x>=0&&y>=0&&Ans<0) return TMax;
	if(x<0&&y<0&&Ans>=0) return TMin;
	return Ans;
}
int main()
{
	int x,y;
	scanf("%x %x",&x,&y);
	printf("%x\n",saturating_add(x,y));
	return 0;
}