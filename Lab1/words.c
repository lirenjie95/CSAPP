#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
/*----------------------------------------------------------*/
#define MOD 90001
#define length 42
struct List
{
	char str[length];
	int flag;
	struct List *next;
};// List is a hashtable element.
struct List *hash[MOD];char s[300000][length];int sj[length];
/*----------------------------------------------------------*/
void Qsort(int l,int r)
{
	int i,j,t;char x[length];
	i = l;j = r;strcpy(x,s[(l+r)>>1])
	while(i <= j)
	{
		while(Num[i] < x) i++;
		while(Num[j] > x) j--;
		if(i<=j)
		{
			t=x[i];a[i]=a[j];a[j]=t;
			i++;j--;
		}
	}
	if(i<r) Qsort(i,r);
	if(l<j) Qsort(l,j);
}
/*----------------------------------------------------------*/
int main()
{
	int n,i,len,tot,key;
	char ss[length];struct List *u,*p;
	scanf("%d",&n);
	for(i = 0;i < MOD;i++)
	{
		hash[i] = (struct List *)malloc(sizeof(struct List));
		hash[i]->str[0] = '\0';
		hash[i]->flag = 0;
		hash[i]->next = NULL;
	}
	tot=0;srand(time(NULL));
	for(i = 0;i < length;i++)
		sj[i] = rand() % MOD;
	// sj[] is an array that can help to calculate the key value.
	while(n--)
	{
		scanf("%s",ss);
		key = 0;
		len = strlen(ss);
		for(i = 0;i < len;i++)
			key = (key + ss[i] - 'a') * sj[i] % MOD;
			// It means that sum ss[i]*sj[i] is the key value.
		key = (key + MOD) % MOD;
		if(strlen(hash[key]->str) == 0)// hash[key] does not exist.
		{
			strcpy(hash[key]->str,ss);
			continue;
		}
		u=hash[key];
		while(u)// hash[key] exists.
		{
			if(strcmp(u->str,ss) == 0)
			{
				if(!u->flag)
				{
					u->flag = 1;
					strcpy(s[tot++],u->str);
				}
				break;
			}
			p = u;
			u = u->next;
		}
		// Finding a place to put the new hashtable.
		if(!u) 
		{
			u = (struct List *)malloc(sizeof(struct List));
			u->next = NULL;
			strcpy(u->str,ss);
			u->flag = 0;
			p->next = u;
		}
	}
	Qsort(1,tot);
	for(i = 0;i < tot;i++)
		printf("%s %d\n",s[i],Num[i]);
	return 0;
}