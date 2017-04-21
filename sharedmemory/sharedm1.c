#include <stdio.h>
#include <string.h>
#include <sys/shm.h>
#include <sys/stat.h>

#define MAX_BUF 1024
#define PERM 0666
#define SHMKEY 9993332

int main()
{
    key_t shm_key = 6166529;
    const int shm_size = 1024;
    
    int shm_id;
    char* shmaddr, *ptr;
    
    printf ("writer started.\n");
    
    /* Allocate a shared memory segment. */
    shm_id = shmget (shm_key, shm_size, IPC_CREAT);
    
    /* Attach the shared memory segment. */
    shmaddr = (char*) shmat (shm_id, 0, 0);
    
    printf ("shared memory attached at address %p\n", shmaddr);
    
    /* Start to write data. */
    shmaddr = "test";
    
    printf("%s\n",shmaddr);
    /* Detach the shared memory segment. */
    shmdt (shmaddr);
    /* Deallocate the shared memory segment.*/
    shmctl (shm_id, IPC_RMID, 0);
    
    return 0;
}