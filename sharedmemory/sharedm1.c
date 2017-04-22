#include <stdio.h>
#include <string.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/sem.h>
#include <sys/ipc.h>

#define MAX_BUF 1024
#define PERM 0666
#define SHMKEY 9993332

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

int main()
{
    char c;
    int shmid;
    key_t key;
    char *shm, *s;
    
    key = 5678;
    
    if ((shmid = shmget(key, MAXSIZE, IPC_CREAT | PERM)) < 0) {
        return 0;
    }
    
    if ((shm = shmat(shmid, NULL, 0)) == (char *) -1) {
        return 0;
    }
    
    s = shm;
    
    for (c = 'a'; c <= 'z'; c++) {
        *s++ = c;
    }
    
    while (*shm != '*') {
        sleep(1);
    }
    
    return 0;
}