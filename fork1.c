#include <stdio.h>
#include <unistd.h>
#define MAX_COUNT 100
void main()
{
	pid_t pid;
	fork();
	//fork();
	//fork();
	pid = getpid();
	
	
		printf("The PID is %d\n",pid);
	
	fork();
	pid = getpid();
		
	printf("The PID is %d\n",pid);
	
	fork();
	pid = getpid();
		printf("The PID is %d\n",pid);
}
