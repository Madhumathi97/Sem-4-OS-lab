#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>

int main()
{
	int pid;
	
	//printf("I AM A PROCESS WITH PID %d\n",(int)getpid());
	pid=fork();
	if(pid<0)
	{
		perror("FORK FAILED\n");
	}
	if(pid==0)
	{ 	
		printf("I AMTHE CHILD PROCESS P2 WITH PID %d\n",(int)getpid());
		pid=fork();
		if(pid<0)
		{
		perror("FORK FAILED\n");
		}
		if(pid==0)
		{ 	
			printf("I AM THE CHILD PROCESS P4 WITH PID %d\n",(int)getpid());
		}
	}
	
	
	
	else if(pid>0)
	{
		printf("I AM THE PARENT PROCESS P1 WITH PID %d\n",(int)getpid());
		pid=fork();
		if(pid<0)
			{
				perror("FORK FAILED\n");
			}
		if(pid==0)
		{ 	
			printf("I AMTHE CHILD PROCESS P3 WITH PID %d\n",(int)getpid());
			pid=fork();
			if(pid<0)
			{
				perror("FORK FAILED\n");
			}
			if(pid==0)
			{ 	
				printf("I AM THE CHILD PROCESS P5 WITH PID %d\n",(int)getpid());
			}
		
			pid=fork();
			if(pid<0)
			{
				perror("FORK FAILED\n");
			}
				
			if(pid==0)
			{ 	
				printf("I AMTHE CHILD PROCESS P6 WITH PID %d\n",(int)getpid());
			}
		}
	}
}
