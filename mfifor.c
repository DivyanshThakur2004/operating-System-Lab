#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

#define FIFO_PATH "/home/geu/Desktop/def"

int main()
{
    int fd;
    char buffer[100];
    ssize_t bytes_read;
    fd = open(FIFO_PATH, O_RDONLY);
    if (fd == -1) {
        perror("Failed to open FIFO for reading");
        return 1;
    }
    bytes_read = read(fd, buffer, sizeof(buffer));
    if (bytes_read == -1) {
        perror("Failed to read from FIFO");
        close(fd);
        return 1;
    }
    if (bytes_read < sizeof(buffer)) {
        buffer[bytes_read] = '\0';
    } else {
        buffer[sizeof(buffer) - 1] = '\0';
    }
    printf("Read from FIFO: %s\n", buffer);
	printf("Number of Bytes Readed from the Pipe: %zd\n",bytes_read);
    close(fd);
    return 0;
}
