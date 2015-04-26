/* user.c - main */

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <stdio.h>
#include<lab0.h>

void halt();

/*------------------------------------------------------------------------
 *  main  --  user main program
 *------------------------------------------------------------------------
 */
		
prch(char c)
{
int i, count=0;
	getpid();
	gettime(34);
	while(count++ < 5) {
		kprintf("%c", c);
		for (i = 0; i< 1000000; i++);
	}
	sleep(5);

}
int prA, prB;

int main()
{
       
        long one = zfunction(0xaabbccdd);
        long two = zfunction(0xabcd08f9);
	//getpid();
	      
	printsegaddress();
	printtos(0xffff);
	syscallsummary_start();
        resume(prA = create(prch,2000,30,"proc A",1,'A'));
	resume(prB = create(prch,2000,30,"proc B",1,'B'));
	//sleep(5);        
	getpid();
	signal(2);
	kprintf("\n%d value of flagsummary",flagsummary);
        
        /*kprintf("%04x\n%d\n%d\n%d\n%d\n",one,i,j,k,l);*/
        kprintf("%04x\n%04x\n\n",two,one);
	kprintf("\n\nHello World, Xinu lives\n\n");
        printprocstks(0,100);
       // kill(prA);
	kill(prB);
        //sleep(5);
	syscallsummary_stop();
	printsyscalls();
	return 0;
}
