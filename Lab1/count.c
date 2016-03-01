#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
/*----------------------------------------------------------*/
#define MOD 90001
#define MAXN 300000
#define length 42
struct List
{
	char str[length];
	int flag;
	struct List *next;
};// List is a hashtable element.
struct List *hash[MOD];
char s[MAXN][length];
int sj[length],Num[MAXN];
FILE *fp;
/*----------------------------------------------------------*/
void Qsort(int l,int r)
{
	int i,j,t,u;char x[length],y[length];
	i = l;j = r;u = Num[(l+r)>>1];
	strcpy(x,s[(l+r)>>1]);
	while(i <= j)
	{
		while(Num[i] < u||(Num[i] == u&&strcmp(x,s[i]) > 0)) i++;
		while(Num[j] > u||(Num[j] == u&&strcmp(x,s[j]) < 0)) j--;
		if(i<=j)
		{
			t = Num[i];Num[i] = Num[j];Num[j] = t;
			strcpy(y,s[i]);strcpy(s[i],s[j]);strcpy(s[j],y);
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
	for(i = 0;i < MOD;i++)
	{
		hash[i] = (struct List *)malloc(sizeof(struct List));
		hash[i]->str[0] = '\0';
		hash[i]->flag = 0;
		hash[i]->next = NULL;
	}
	tot=0;
	srand(time(NULL));
	for(i = 0;i < length;i++)
		sj[i] = rand() % MOD;
	// sj[] is an array that can help to calculate the key value.
	fp = fopen("middle.txt","r");
	fscanf(fp,"%d",&n);
	while(n--)
	{
		fscanf(fp,"%s",ss);
		key = 0;
		len = strlen(ss);
		for(i = 0;i < len;i++)
			key = (key + ss[i] - 'a') * sj[i] % MOD;
			// It means that sum ss[i]*sj[i] is the key value.
		key = (key + MOD) % MOD;
		if(strlen(hash[key]->str) == 0)// hash[key] does not exist.
		{
			strcpy(hash[key]->str,ss);
			hash[key]->flag = 1;
			continue;
		}
		u=hash[key];
		while(u)// hash[key] exists.
		{
			if(strcmp(u->str,ss) == 0)
			{
				u->flag++;
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
			u->flag = 1;
			p->next = u;
		}
	}
	fclose(fp);
	for(i = 0;i < MOD;i++)
		if(strlen(hash[i]->str) != 0)
		{
			u = hash[i];
			while(u)
			{
				tot++;
				strcpy(s[tot],u->str);
				Num[tot] = u->flag;
				u = u->next;
			}
		}
	Qsort(1,tot);
	fp = fopen("result.txt","w");
	for(i = 1;i <= tot;i++)
		fprintf(fp,"%s %d\n",s[i],Num[i]);
	fclose(fp);
	return 0;
}