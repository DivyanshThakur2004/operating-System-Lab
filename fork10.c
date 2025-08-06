#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
int main()
{
	pid_t child_pid = fork();
	if(child_pid == 0){
		printf("I am the Zombie process Exiting The Execution but still has entry in process table. My PID is %d and my parent PID is %d\n",getpid(),getppid());
		sleep(1);
	}else if(child_pid > 0){
		wait(0);
		exit(0);
	}
	else{
		printf("Fork Failed\n");
	}
	return 0;
}
