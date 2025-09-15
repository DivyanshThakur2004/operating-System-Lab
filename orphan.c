#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
int main()
{
    pid_t pid = fork();
    if(pid > 0)
    {
        printf("I am The Parent Process PID = %d my child's PID = %d and now imma terminate myself, peace out\n",getpid(),pid);
        _exit(0);
    }
    else if(pid == 0)
    {
        printf("I am The Child Process, PID = %d my parent's PID is %d\n",getpid(),getppid());
        sleep(5);
        printf("Now I am Adopted By init process, My PID is %d and my new Parent's PID is %d\n",getpid(),getppid());
    }
    else
    {
        printf("Fork Failed\n");
    }
    return 0;
}
