#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
int main()
{
    char msg[] = "PIPE CREATION SIMULATION";
    char buffer[100];
    int fd[2];
    if(pipe(fd) == -1)
    {
        printf("Pipe Creation Failed\n");
        return 0;
    }
    pid_t p = fork();
    if(p > 0)
    {
        printf("I am the parent process and now i will start writting\n");
        close(fd[0]);
        int written = write(fd[1],msg,strlen(msg) + 1);
        printf("The Parent has written it's content and now it will close it\n");
        printf("The Size of the File sent is %d\n",written);
        close(fd[1]);
    }
    else if(p == 0){
        printf("I am the Child Process and i will read whatever my parent has written\n");
        close(fd[1]);
        int r = read(fd[0],buffer,sizeof(buffer));
        printf("The Child Successfully readed: %s\n",buffer);
        printf("The Size of the file readed/recieved is %d\n",r);
        close(fd[0]);
    }
    else{
        printf("Fork Failed\n");
    }
    return 0;
}
