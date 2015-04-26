/* gettime.c - gettime */

#include <conf.h>
#include <kernel.h>
#include <date.h>
#include<lab0.h>
#include<proc.h>
#include<stdio.h>
extern int getutim(unsigned long *);

/*------------------------------------------------------------------------
 *  gettime  -  get local time in seconds past Jan 1, 1970
 *------------------------------------------------------------------------
 */
SYSCALL	gettime(long *timvar)
{
    /* long	now; */

	/* FIXME -- no getutim */
	if(flagsummary==1)
	{	
	 setprintsyscalls(currpid,1);	
	}
	//kprintf("SYSCALL	gettime(long *timvar)");
    return OK;
}
