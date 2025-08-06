#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() {
    pid_t pid1, pid2;

    pid1 = fork();
    if (pid1 < 0) {
        perror("Fork failed");
        exit(1);
    }

    if (pid1 == 0) {
        sleep(5);
        printf("Orphan Child: PID = %d, New Parent PID = %d\n", getpid(), getppid());
        exit(0);
    } else {
        printf("Parent PID = %d created orphan child PID = %d and continues execution\n", getpid(), pid1);
    }
    pid2 = fork();
    if (pid2 < 0) {
        perror("Fork failed");
        exit(1);
    }

    if (pid2 == 0) {
        printf("Zombie Child: PID = %d, Parent PID = %d (will become zombie)\n", getpid(), getppid());
        exit(0);
    } else {
        sleep(10);
        waitpid(pid2, NULL, 0);
        printf("Parent reaped zombie child PID = %d\n", pid2);
    }
    waitpid(pid1, NULL, 0);
    return 0;
}
