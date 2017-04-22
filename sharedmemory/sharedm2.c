#include <stdio.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/sem.h>
#include <sys/ipc.h>

#define MAXSIZE 27

void P(int semid, int index) {
    int ret;
    struct sembuf op;
    
    op.sem_num = index;
    op.sem_op = -1;
    op.sem_flg = SEM_UNDO;
    
    if ((ret = semop(semid, &op, 1)) == -1) {
        printf("Error");
    }
}

void V(int semid, int index) {
    int ret;
    struct sembuf op;
    
    op.sem_num = index;
    op.sem_op = 1;
    op.sem_flg = SEM_UNDO;
    
    if ((ret = semop(semid, &op, 1)) == -1) {
        printf("Error");
    }
}

int main ()
{
    int shmid;
    key_t key;
    char *shm, *s;
    
    key = 5678;
    
    if ((shmid = shmget(key, MAXSIZE, 0666)) < 0) {
        return 0;
    }
    
    if ((shm = shmat(shmid, NULL, 0)) == (char *) -1) {
        return 0;
    }
    
    //Now read what the server put in the memory.
    for (s = shm; *s != '\0'; s++) {
        printf("%c",*s);
        //putchar(*s);
    }
    putchar('\n');

    *shm = '*';
    
    return 0;
}