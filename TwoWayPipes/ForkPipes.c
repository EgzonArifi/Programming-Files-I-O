#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

/*  Parent: reads from P1_READ, writes on P1_WRITE */
/*  Child:  reads from P2_READ, writes on P2_WRITE */
#define P1_READ     0
#define P2_WRITE    1
#define P2_READ     2
#define P1_WRITE    3

#define NUM_PIPES   2

int main(int argc, char *argv[])
{
    int fd[2*NUM_PIPES];
    int len, i;
    pid_t pid;
    /* create all the descriptor pairs we need */
    for (i=0; i<NUM_PIPES; ++i) {
        if (pipe(fd+(i*2)) < 0) {
            printf("Failed to allocate pipes");
            exit(0);
        }
    }
    /* fork() returns 0 for child process, child-pid for parent process. */
    if ((pid = fork()) < 0) {
        printf("Failed to fork process");
        exit(0);
    }
    /* if the pid is zero, this is the child process */
    if (pid == 0) {
        // Child. Start by closing descriptors wl
        //  don't need in this process
        // Parent. close unneeded descriptors
        close(fd[P1_READ]);
        close(fd[P1_WRITE]);
        /* used for output */
        pid = getpid();
        printf("Child with pid %d: Sending to parent\n", pid);
        /* send a value to parent */
        int data [5] = {6,7,8,9,10};
        if(  write(fd[P2_WRITE], &data, sizeof(int)*5) == -1) {
            perror("Child: Failed to send value to parent ");
            exit(EXIT_FAILURE);
        }
        /* now wait for a response */
        int buf [5] = {};
        len = read(fd[P2_READ], &buf, sizeof(int)*5);
        for (int i = 0; i < 5; i++) {
            printf("\nElements recieved from child is %d\n ",buf[i]);
        }
        if (len < 0) {
            perror("Child: failed to read value from pipe");
            exit(EXIT_FAILURE);
        }
        else if (len == 0) {
            /* not an error, but certainly unexpected */
            fprintf(stderr, "Child(%d): Read EOF from pipe", pid);
        }
        /* close down remaining descriptors */
        close(fd[P2_READ]);
        close(fd[P2_WRITE]);
        
        return EXIT_SUCCESS;
    } else {
        /* Parent. close unneeded descriptors */
        close(fd[P2_READ]);
        close(fd[P2_WRITE]);
        /* used for output */
        int childPid = pid;
        pid = getpid();
        /* send a value to the child */
        printf("Parent with pid %d: Sending to child\n", pid);
        int data [5] = {1,2,3,4,5};
        sleep(2);
        if(  write(fd[P1_WRITE], &data, sizeof(int)*5) == -1) {
            perror("Parent: Failed to send value to child ");
            exit(EXIT_FAILURE);
        }
        sleep(2);
        /* now wait for a response */
        int buf [5] = {};
        len = read(fd[P1_READ], &buf, sizeof(int)*5);
        for (int i = 0; i < 5; i++) {
            printf("\nElements recieved from parent is %d\n ",buf[i]);
        }
        kill(childPid, SIGKILL);
        if (len < 0) {
            perror("Parent: failed to read value from pipe");
            exit(EXIT_FAILURE);
        }
        else if (len == 0) {
            /* not an error, but certainly unexpected */
            fprintf(stderr, "Parent(%d): Read EOF from pipe", pid);
        }
        /* close down remaining descriptors */
        close(fd[P1_READ]);
        close(fd[P1_WRITE]);
        printf("Parent exiting\n");
        /* kill child process */
        exit(0);
    }
    return EXIT_SUCCESS;
}
