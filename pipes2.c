#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

#define MSGSIZE 16

char *msg1 = "Hello, World #1";
char *msg2 = "Hello, World #2";
char *msg3 = "Hello, World #3";

main()
{

	char inbuf[MSGSIZE];
	int p[2],j;
	pid_t pid;

	/*open pipe*/
	if(pipe(p) == -1)
	{

		perror("pipe call");
		exit(1);
	}

	switch(pid = fork())
	{
		case -1:
			perror("Fork Failure");
			exit(2);	

		case 0:
			/*if child then,write down pipe*/
			close(p[0]);
			write(p[1],msg1,MSGSIZE);
			write(p[1],msg2,MSGSIZE);
			write(p[1],msg3,MSGSIZE);
			close(p[1]);
			break;

		default:
			/*If parent then read from pipe*/
			close(p[1]);
			while(read(p[0],inbuf,MSGSIZE)!=0)
				printf("%s\n",inbuf);
			wait(NULL);
	}
	exit(0);
}
