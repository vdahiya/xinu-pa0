#include<conf.h>
#include<kernel.h>
#include<stdio.h>
#include<proc.h>
#include<lab0.h>

void printsyscalls()

{
        int tid;
        int syscall;
	struct pentry *proc;
	//kprintf("we are in printsyscalls");
	for(tid =0;tid<=NPROC;tid++)
        {
        	proc=&proctab[tid];
        	for(syscall=1;syscall<7;syscall++)
		{
        		if(proc->printsyscalls[syscall]==100)
        		{
			switch(syscall)
			{
			
                    
			
			case 1:
				
                        kprintf("\nthe process id is %d and the syscall invoked  is SYSCALL	gettime(long *timvar)\n",tid);
			break;
			case 2:
			
                        kprintf("the process id is %d and the syscall invoked  is SYSCALL kill(int pid)\n",tid);
			break;
			case 3:
			
                        kprintf("the process id is %d and the syscall invoked  is SYSCALL signal(int sem)\n",tid);
			break;
			case 4:
			
                        kprintf("the process id is %d and the syscall invoked  is SYSCALL	sleep(int n)\n",tid);
			break;
                        case 5:
                        
                        kprintf("the process id is %d and the syscall invoked  is SYSCALL	wait(int sem)\n",tid);
			break;
			case 6:			
                        kprintf("the process id is %d and the syscall invoked  is SYSCALL	getpid()\n",tid);
			break;
                        }
			}


        	}
	}
}

void setprintsyscalls(int pid,int syscall)

{
	struct pentry *proc=&proctab[pid];
        proc->printsyscalls[syscall]=100;
 }

void syscallsummary_start()
{
	 flagsummary =1;
}


void syscallsummary_stop()
{
	 flagsummary =0; 
} 
