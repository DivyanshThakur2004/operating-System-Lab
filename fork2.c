#include <stdio.h>
#include <unistd.h>
#define MAX_COUNT 100
void main()
{
	pid_t pid;
	pid = getpid();
	for(int i=0;i<3;i++)
	{
		fork();
		pid = getpid();
		printf("PID = %d\n",pid);
	}
}
