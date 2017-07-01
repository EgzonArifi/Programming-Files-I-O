#include <stdio.h>
#include "string.h"
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>

int main(int argc, char * argv[]) {

    pid_t ppid;
    ppid = getppid();
    
    printf("Before sleep\n");
    printf("parent pid => %d\n",ppid);
    
    for (int i = 0; i <= 2; i++) {
        printf("%d\n",i);
        sleep(1);
    }

    kill(ppid, SIGUSR1);
    
    return 0;
}