#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <unistd.h>

#define SHM_SIZE 1024

int main() {
    int shmid;
    char *shared_memory;
    key_t key;
    pid_t pid;
    
    printf("\t\tOUTPUT\n");
    printf("Name: Divyansh Thakur\t\tRoll no.: 25\n");
    
    key = ftok(".", 65);
    printf("Unique key created using ftok: %d\n", key);
    
    shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666);
    
    if (shmid < 0) {
        perror("shmget");
        exit(1);
    }
    
    printf("Shared memory id after creation: %d\n", shmid);
    
    shared_memory = (char*) shmat(shmid, NULL, 0);
    
    if (shared_memory == (char*) -1) {
        perror("shmat");
        exit(1);
    }
    
    pid = fork();
    
    if (pid < 0) {
        perror("fork");
        exit(1);
    }
    
    else if (pid == 0) {
        printf("Child (PID: %d) writing data into shared memory...\n", getpid());
        printf("Shared memory attached at address (shmaddr): %p\n", (void*)shared_memory);
        strcpy(shared_memory, "Hello to Parent");
        printf("Finished writing\n");
        exit(0);
    }
    
    else {
        sleep(1);
        
        printf("Parent (PID: %d) reading from shared memory\n", getpid());
        printf("Shared memory attached at address (shmaddr): %p\n", (void*)shared_memory);
        printf("Parent received msg: %s\n", shared_memory);
        printf("Size: %lu bytes\n", strlen(shared_memory));
        
        shmdt(shared_memory);
        
        printf("Shared memory id after detaching: %d\n", shmid);
        
        shmctl(shmid, IPC_RMID, NULL);
    }
    
    return 0;
}
