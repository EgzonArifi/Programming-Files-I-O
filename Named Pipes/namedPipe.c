#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define MAX_BUF 1024
#define PERM 0666

int main()
{
    int fd;
    char * myfifo = "myfifo";
    char line[MAX_BUF];
    
    /* create the FIFO named pipe */
    if (mkfifo(myfifo, PERM) == -1) {
        exit(1);
    }
    
    // write something
    printf("Enter something: ");
    fgets(line, MAX_BUF, stdin);
    
    fd = open(myfifo, O_WRONLY);
    write(fd, line, sizeof(line));
    close(fd);
    /* remove the FIFO */
    unlink(myfifo);
    
    return 0;
}