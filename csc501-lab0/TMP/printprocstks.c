#include<conf.h>
#include<kernel.h>
#include<stdio.h>
#include<proc.h>

static unsigned long* esp;

void printprocstks(int prioritylow, int priorityhigh)
{
	int pid=0;
	int tid=0;
 	unsigned long *sp;
	struct pentry *proc;
        kprintf("\nNPROC =%d\n\n",NPROC);
	while(tid<NPROC)
	{	
		pid = tid;
		tid++;
                proc =&proctab[pid];
                if ( pid != 0 && isbadpid(pid) )
		{
               // kprintf("i was in first if\n");	
		continue;
		}
	
		
               /* if((proctab[pid].pstate) == PRFREE)
		{
               // kprintf("i was in second if\n");
		continue;
		}*/
		
		if (pid == currpid)
		{
               // kprintf("i was in third if\n ");
           	asm("movl %esp,esp");
			sp = esp;
		}
                else 
                {
               // kprintf("i was in else\n");
		sp = (unsigned long *)proctab[pid].pesp;

		}

		
      		if(((proc->pprio)>=prioritylow) &&((proc->pprio)<=priorityhigh) && (proc->pstate!=PRFREE))
		
  		kprintf ("Proc name = %s\n process id  = %d \n process priority= %d \nStack: Base = %10x\nsize = %d \nlimit = %10x \nstackPtr = %10x\n", proc->pname, \
		 pid,proc->pprio,(unsigned long*)proc->pbase, \
                (unsigned long*)proc->pstklen, (unsigned long*) proc->plimit, sp);				
		
	


	
	}
	

return 0;
}
