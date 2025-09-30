#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#define FIFO_PATH "/home/geu/Desktop/def"
int main()
{
    const char *message = "Dehradun";
    int fd;
    if (mkfifo(FIFO_PATH, 0666) == -1) {
        if (errno != EEXIST) {
            perror("Named Pipe Creation Error");
            return 1;
        }
    }
    printf("FIFO created/opening and writing to the pipe...\n");
    fd = open(FIFO_PATH, O_WRONLY);
    if (fd == -1) {
        perror("FIFO open failed");
        return 1;
    }
    if (write(fd, message, strlen(message) + 1) == -1) {
        perror("Write failed");
        close(fd);
        return 1;
    }
    printf("Number of bytes written: %ld\n", strlen(message) + 1);
    printf("Program executed successfully\n");
    close(fd);
    return 0;
}
