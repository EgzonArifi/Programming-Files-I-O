#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define MAX_BUF 1024

int main()
{
    int fd;
    char * myfifo = "myfifo";
    char buf[MAX_BUF];
    
    for (int i = 0; i < 5; i++) {
        printf("%d",i);
        sleep(1);
    }
    /* open, read, and display the message from the FIFO */
    fd = open(myfifo, O_RDONLY);
    read(fd, buf, MAX_BUF);
    printf("Received: %s\n", buf);
    close(fd);
    
    return 0;
}