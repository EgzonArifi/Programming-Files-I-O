/*
 Ky program eshte nje klient i cili komunikon permes message queues
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include <ctype.h>
#include <fcntl.h>

/* Definimi i struktures dhe variablave per program */
typedef struct messagebuffer  {
    long msg_to;
    int count;
    char buffer[20];
} MESSAGE;

int mid,clientId;
key_t key;
struct msqid_ds buf;
MESSAGE msg;

int main(int argc, char** argv) {
    /* Kontrollimi i argumenteve */
    if(argc == 2) {
        clientId = atoi(argv[1]);
        key = 12344;
        
        /* Krijimi i msg queue */
        if ((mid = msgget(key, 0666)) < 0) {
            perror("msgget");
            exit(1);
        }
        printf("Message Queue ID: %d\n", mid);
        printf("Client ID: %ld\n", (long)getpid());
        
        /* Unaze e pafundme qe lexon te dhenat e strukturuara nga msg queue */
        while(1) {
            if(msgrcv(mid, &msg, sizeof(struct messagebuffer), clientId, 0) <0) {
                perror("msgrcv");
                exit(-1);
            }
            printf("Message recieved %s\n", msg.buffer);
        }
    } else {
        printf("Invalid arguments\n");
    }
    return (EXIT_SUCCESS);
}
