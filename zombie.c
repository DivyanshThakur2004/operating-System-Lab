#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
int main()
{
    pid_t pid = fork();
    if(pid==0)
    {
        printf("I am the child Process, My PID is %d and my Parent's PID is %d and now i will terminate myself\n",getpid(),getppid());
        _exit(0);
    }
    else if(pid > 0)
    {
        printf("I am Parent Process my PID is %d and my Child's PID is %d now i will go to sleep without waiting for my child\n",getpid(),pid);
        sleep(5);
        printf("I slept for 5 seconds and now i will terminate myself\n");
    }
    else{
        printf("Fork Failed\n");
    }
    return 0;
}
