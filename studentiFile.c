#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#include <stdbool.h>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>

int main(int argc, char * argv[]) {
    
    int fd[2];
    pid_t ppid;
    ppid = getppid();
    
    printf("Before sleep\n");
    printf("parent pid => %d\n",ppid);
    
    for (int i = 0; i <= 2; i++) {
        printf("%d\n",i);
        sleep(1);
    }
    
    dup2(fd[1], STDOUT_FILENO);
    close(fd[0]);
    
    write(fd[1], "TestTest", (strlen("TestTest")+1));
    
    printf("After sleep\n");
    //kill(ppid,SIGUSR1);
    return 0;
}