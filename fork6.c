#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    for(int i = 0; i < 3 ; i++){
        int a = fork();

        if (a < 0) {
            perror("fork failed");
            return 1;
        } else if (a == 0) {
            printf("Hello from child %d\n", i);
            printf("A (in child) is %d\n", a);
            printf("My PID is %d\n", getpid());
            printf("My Parent PID is %d\n", getppid());
            return 0;
        } else {

        }
    }

    printf("Parent process is done with forking.\n");

    while(wait(NULL) > 0);

    return 0;
}
