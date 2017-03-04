#include "cachelab.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <getopt.h>

int s, E, b;
FILE *f;
int hit = 0, miss = 0, replace = 0;
typedef struct {
	unsigned LRUtime;
	unsigned tag;
}record;
record *cache;

void FindData(unsigned address, unsigned time) {
	unsigned Tag = address>>b>>s;
	unsigned SetIndex = (address>>b)&((1<<s)-1);
	record *SetBlock = cache+E*SetIndex;
	record *Replace = SetBlock;
	int i;
	for(i=0;i<E;i++){
		if((SetBlock+i)->LRUtime==0){
			miss++;
			(SetBlock+i)->LRUtime = time;
			(SetBlock+i)->tag = Tag;
			return;
		}
		else if((SetBlock+i)->tag==Tag){
			hit++;
			(SetBlock+i)->LRUtime = time;
			return;
		}
		else if((SetBlock+i)->LRUtime<Replace->LRUtime)
			Replace = SetBlock+i;
	}
	miss++;
	replace++;
	Replace->tag = Tag;
	Replace->LRUtime = time;
}

int main(int argc, char **argv)
{
	FILE *fin;
	char opt;
	unsigned address,time = 0;
	while((opt=getopt(argc,argv,"s:E:b:t:"))!=-1){
		// It means extract s,E,b,t and these numbers(->optarg) related to them.
		switch(opt){
		case 's':
			s = atoi(optarg);// atoi() can turn string to number
			break;
		case 'E':
			E = atoi(optarg);
			break;
		case 'b':
			b = atoi(optarg);
			break;
		case 't':
			fin = fopen(optarg,"r");
		}
	}
	cache = (record*)malloc(sizeof(record)*E<<s);
	memset(cache,0,sizeof(record)*E<<s);
	while(fscanf(fin,"%c%x,%*d\n",&opt,&address)>0){
		//Data is like this :M 0421c7f0,4
		time++;
		if(opt=='M') hit++;// M means modify, get a used data and find a new one.
		if(opt=='M'||opt=='L'||opt=='S') FindData(address,time);// L: load, S: store
	}
    printSummary(hit, miss, replace);
    return 0;
}