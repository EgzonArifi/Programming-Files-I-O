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
    msg.mtype = 1;
    printf("Enter message: ");
    fgets(msg.message, 80, stdin);

    printf("Enter nota: ");
    scanf("%d", &msg.nota);

    if (msgsnd (msgid, &msg, sizeof(msg) - sizeof(long),0) == -1) {
        printf("Error sending message\n");
        exit(0);
    }
    
    
    return 0;
}