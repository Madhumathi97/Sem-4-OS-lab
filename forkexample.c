#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
void main()
{
	int pid;
	printf("I'm a process with pid %d\n",(int)getpid());
	pid =fork();
	if(pid<0)
	{
		perror("Fork failed");	
	}
	if(pid==0)
	{
		printf("I'm child process with pid %d\n",(int)getpid());
	}

	else if(pid>0)
	{
		printf("I'm parent process with pid %d\n",(int)getpid());
	}
}
