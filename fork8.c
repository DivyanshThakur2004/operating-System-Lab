#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h>     
#include <sys/wait.h>   

int main()
{
    pid_t pid;
    int status;
    pid = fork();
    if(pid == 0)
    {
        printf("I am the Child Process (PID = %d)\n",getpid());
        sleep(2);
        printf("Child Process Exiting.\n");
    }
    else if(pid > 0)
    {
        wait(0);
        printf("I am the waiting Parent Process (PId = %d).\nMy retrieved Child ID is %d.\n",getpid(),pid);
    }
    else{
        printf("Error, forking Process Failed.\n");
    }
}
