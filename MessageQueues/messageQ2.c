#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define MAX_BUF 1024
#define PERM 0666
#define KEY 9993331

struct msg_t {
    long mtype;
    char message[80];
    int nota;
};

int main()
{
    int msgid;
    struct msg_t msg;
    
    if ((msgid = msgget(KEY,PERM|IPC_CREAT)) == -1) {
        printf("Error\n");
        exit(1);
    }
    
    if (msgrcv(msgid, &msg, sizeof(msg) - sizeof(long),1,0) == -1) {
        printf("Error");
        exit(0);
    }
    printf("Message Received: %s\n",msg.message);
    printf("Nota: %d\n",msg.nota);
    
}