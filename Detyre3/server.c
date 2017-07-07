/*
 Ky program eshte nje server i cili komunikon permes message queues
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

int mid;
key_t key;
size_t buf_length;
struct msqid_ds buf;
MESSAGE msg;

int read_data();

int main(int argc, char** argv) {
    key = 12344;
    /* Krijimi i message queue dhe trajtimi i problemeve */
    if((mid = msgget(key, IPC_CREAT | 0666)) < 0){
        perror("msgget");
        exit(1);
    } else {
        (void) fprintf(stderr,"msgget: msgget succeeded: msqid = %d and key %d\n", mid,key);
    }
    printf("Message Queue ID: %d\n", mid);
    printf("Client ID: %ld\n", (long)getpid());
    (void) strcpy(msg.buffer, "mesazhi i detyres 3");
    
    /* Nje unaze e pafundme qe do te lexoj dhe shkruaj mesazhin e pranuar permes msg queue ne terminal */
    while(1) {
        sleep(1);
        msg.msg_to = read_data();
        printf("Message to%ld\n",msg.msg_to );
        if (msgsnd(mid, &msg, sizeof(struct messagebuffer ), 0) < 0) {
            perror("msgsnd");
            exit(1);
        } else {
            printf("Message send to client with ID to %ld\n",msg.msg_to );
        }
    }

    msgctl(mid, IPC_RMID, (struct msqid_ds *) 0);
    return (EXIT_SUCCESS);
}
/* Funksioni read data i cili gjeneron nje number random nga 1 deri ne 5 */
int read_data() {
    srand(time(NULL));
    int randomnumber;
    randomnumber = 1 + rand() % 5;
    if(randomnumber) {
        return randomnumber;
    }
    else return -1;
}
