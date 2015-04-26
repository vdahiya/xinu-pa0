/* getpid.c - getpid */

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include<lab0.h>
/*------------------------------------------------------------------------
 * getpid  --  get the process id of currently executing process
 *------------------------------------------------------------------------
 */
SYSCALL getpid()
{
       // kprintf("SYSCALL getpid()");
        if(flagsummary==1)
	{
	setprintsyscalls(currpid,6);
	}	
	return(currpid);
}
