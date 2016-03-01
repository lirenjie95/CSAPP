#include <stdio.h>
#include <string.h>
#define MAXN 30000
#define length 50
char str[MAXN][length];
/*----------------------------------------------------------*/
int main()
{
	FILE *fp;char ch;int len,count;
	fp = fopen("raw.txt","r");
	count = 0;
	while(!feof(fp))
    {
        ch = getc(fp);
        //if(ch == ' '||ch == 10)
		//	continue;
        if((ch >= 'a'&&ch <= 'z')||(ch >= 'A'&&ch <= 'Z'))// A new word.
        {
            len=0;count++;
            while((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z')||(ch=='\''))
            {
                if(ch >= 'A'&&ch <= 'Z') ch = ch+'a'-'A';
                str[count][len++] = ch;
                ch = getc(fp);
            }
            str[count][len++] = '\0';
        }
    }
	fclose(fp);
	fp = fopen("middle.txt","w");
	fprintf(fp,"%d\n",count);
	for(len = 1;len <=count;len++)
		fprintf(fp,"%s\n",str[len]);
	fclose(fp);
	return 0;
}
