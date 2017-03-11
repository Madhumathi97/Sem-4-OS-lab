#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main()
{
	int childpid;
	int count1=0,count2=0;
	printf("BEFORE IT FORKS!!\n");
	childpid=fork();
	if(childpid==0)
	{
		printf("THIS IS A CHILD PROCESS WITH PID %d\n",(int)getpid());
		while(count1<10)
		{
			printf("CHILD PROCESS: %d\n",count1);
			sleep(1);
			count1++;
		}
	}
	else
	{
		printf("THIS IS A PARENT PROCESS WITH PID %d\n",(int)getpid());
		while(count2<20)
		{
			printf("PARENT PROCESS: %d\n",count2);
			sleep(1);
			count2++;
		}
	}
}
