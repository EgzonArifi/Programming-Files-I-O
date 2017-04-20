#include <stdio.h>
#include "string.h"
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>

static int received = 0;

void readSignal(int sig)
{
    if (sig == SIGUSR1)
    {
        received = 1;
    }
}
int main(int argc, char * argv[]) {
    
    printf("Test before exec\n");

    signal(SIGUSR1,readSignal);

    int pid = fork();
    switch (pid) {
        case -1:
            printf("Fork Failed");
            break;
        case 0:
            printf("In child process (pid = %d)\n", getpid());
            execl("./studentiFile","Child", (char *)0);
            break;
        default:
            wait((int *)0);
            printf("process (pid = %d)\n", getpid());
            printf("child sleep completed\n");
            
            while (!received);
            printf("SIGUSR1 received.\n");
            
            exit(0);
            break;
    }
    
    return 0;
}
