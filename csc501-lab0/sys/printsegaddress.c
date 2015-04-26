#include<stdio.h>
extern char etext,edata,end;

void printsegaddress()
{
        unsigned char *tmp = &etext;
        unsigned char *tmpq= &edata;
	int i=0;
	int j=0;
	kprintf("first address past\n");
	kprintf(" program text or  etext= %d and in hex %10x\n",&etext,&etext);
	kprintf(" initialized data or edata= %d and in hex %10x\n",&edata,&edata);
	kprintf(" uninitialized data or end=   %d and in hex %10x\n",&end,&end);
	while(i<4)
	{
        tmp--;
	kprintf("four byte contents preceding etext->contents =%10x,address=%10x,\n",*(tmp),tmp);
	i++;
	}

	i=0;
	while(i<4)
	{
        tmpq--;	
	kprintf("four byte contents preceding edata-> contents =%10x,address=%10x\n",*(tmpq),tmpq);
	i++;
        }
	 tmp=&etext;
	 tmpq= &edata;
	
	while(j<4)
	{
	kprintf("four byte contents suceeding etext-> contents= %10x,address=%10x\n",*(tmp),tmp);
        tmp++;
	j++;
        }
        
        j=0;
	while(j<4)
	{
	kprintf("four byte contents suceeding edata-> contents= %10x,address=%10x\n",*(tmpq),tmpq);
	tmpq++;
	j++;
	}
	return 0;
}

