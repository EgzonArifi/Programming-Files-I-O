#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define MAX_BUF 1024

int main(int argc, char * argv[]) {
    
    int fd;
    char *fifo = "myfifo";
    char text[MAX_BUF];
    
    for (int i = 0; i < 5; i++) {
        printf("%d",i);
        sleep(1);
    }
    
    fd = open(fifo, O_RDONLY);
    read(fd, text, MAX_BUF);
    printf("Received: %s\n", text);
    close(fd);
    
    return 0;
}