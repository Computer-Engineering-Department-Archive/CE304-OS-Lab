#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define SHMSIZE 50

int main()
{
    int shmid;
    key_t key;
    key = 3232;

    if ((shmid = shmget(key, SHMSIZE, IPC_CREAT | 0666)) < 0) {
        perror("shmget");
        exit(1);
    }

    char *shm;
    if ((shm = shmat(shmid, NULL, 0)) == (char *) -1) {
        perror("shmat");
        exit(1);
    }

    printf("Writing my message\n");
    sprintf(shm, "Can you hear me?");

    
    printf("Waiting for the reader\n");
    while (*shm != '~')
        sleep(1);
    
    printf("Detach shared memory\n");
    if (shmdt(shm) == -1) {
        perror("shmdt");
        exit(1);
    }

    if(-1 == (shmctl(shmid, IPC_RMID, NULL)))
    {   
        perror("shmctl");
        exit(1);
    }   

    exit(0);
}
