#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
int main()
{
	pid_t pid;
	pid = fork();
	if(pid>0)
	{
		printf("Parent Process with PID = %d is Terminating\n",getpid());
		exit(0);
	} else if(pid == 0){
		sleep(5);
		printf("Child Process PID = %d it's Parent ID = %d is now an orphan and adopted by init process :(\n",getpid(),getppid());
	}
	else{
		printf("Fork Failed, please try again\n");
		exit(1);
	}
	return 0;
}
