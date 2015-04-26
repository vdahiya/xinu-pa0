#include<stdio.h>

static unsigned long *esp;
static unsigned long *ebp;
void printtos(int mask)
{
	//kprintf("we are here\n");
	//int a =4;
	//int b= 5;
	//int c=6;
	//int d= 7;
	asm("movl %ebp,ebp");
       
	kprintf("top of stack contents after function call to printos %10x\n",ebp);
	
	kprintf("top of stack contents before function call to printos %10x\n",ebp+2);
	int i =0;
	asm("movl %esp,esp");
        unsigned long* spfpr =esp;
        while(i<6)
	
        {
        if((mask&(*spfpr))!=0)
        { 
        kprintf("contents of stack below stack location at stack + %d address = %10x contents = %10x\n",i,spfpr,*spfpr);
        }
        i++;
        spfpr++;
        }
        
        
         
	
}
