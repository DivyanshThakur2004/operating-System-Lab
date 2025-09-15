#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
int main()
{
    pid_t pid = fork();
    if(pid == 0)
    {
        printf("I am Child Process. My PID is %d and my parent's PID is %d. Now i am going to sleep for 5 seconds\n",getpid(),getppid());
        sleep(5);
        printf("Woke up after 5 seconds and now i will be terminating, Bye:)\n");
    }
    else if(pid>0)
    {
        printf("I am The Parent Process. My PID is %d and my child's PID is %d. Now i will wait till my child is Terminated\n",getpid(),pid);
        wait(NULL);
        printf("My Child has been Terminated and now i will Terminate myself as well. Good bye\n");
    }
    else{
        printf("Fork Failed\n");
    }
    return 0;
}
