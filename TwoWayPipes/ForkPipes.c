/*
 This program will enable two way communication between
 parent and child process
 */
#define _POSIX_SOURCE
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/wait.h>

/* Helper method to write characters in the pipe */
void writeToPipe (int file) {
    int data[5] = {6,7,8,9,10};
    int i;
    for (i = 0; i < 5; i++) {
        write(file, &data[i], sizeof(int));
        printf("\nElement %d writen from child is %d\n",i,data[i]);
    }
    write(file, &data, sizeof(int));
    close(file);
}
/* Helper method to read characters from the pipe */
void readFromPipe (int file) {
    int c;
    int buffer [5] = {};
    int i;
    for (i = 0; i < 5; i++) {
        read(file, &buffer[i], sizeof(int));
        printf("\nElement %d received from parent is %d\n",i,buffer[i]);
    }
    close(file);
}

int main(int argc, char * argv[]) {
    pid_t pid;
    int myPipe[2];
    
    /* Create the pipe */
    if (pipe(myPipe)) {
        fprintf(stderr, "Pipe failed\n");
        return 0;
    }
    
    /* Create the cild process */
    pid = fork();
    if (pid == (pid_t) 0) {
        /* Here is child process */
        close(myPipe[0]);
        writeToPipe(myPipe[1]);
        return 0;
    } else if (pid < (pid_t) 0) {
        /* The fork failed */
        fprintf(stderr, "Fork failed\n");
        return 0;
    } else {
        /* Parent process */
        close(myPipe[1]);
        readFromPipe(myPipe[0]);
        wait(NULL);
        return 0;
    }
    
    return 0;
}