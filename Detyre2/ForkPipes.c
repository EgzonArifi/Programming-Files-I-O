/*
 Ky program krijon nje proces femije, dhe me pastaj realizohet dergimi i disa te dhenave.
 Ketu procesi prind i dergon te dhenat 1,2,3,4,5 te procesi prind dhe procesi femije do te dergoj te dhenat 6,7,8,9,10 te prindi
 Paraqitja behet ne stdout
 Pas pranimit te shenimeve procesi prind e terminon procesin femije dhe perfundon programi
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>

/* Procesi prind lexon prej P1_READ, shkruan ne P1_WRITE */
/* Procesi femije lexon prej P2_READ, shkruan ne P2_WRITE */
#define P1_READ     0
#define P2_WRITE    1
#define P2_READ     2
#define P1_WRITE    3

#define NUM_PIPES   2

int main(int argc, char *argv[])
{
    int fd[2*NUM_PIPES];
    int len, i;
    pid_t pid;
    
    /* krijimi i te gjithe paleve qe na duhen */
    for (i=0; i<NUM_PIPES; i++) {
        if (pipe(fd+(i*2)) < 0) {
            printf("Procesi i alokimit te pipes deshtoi\n");
            exit(0);
        }
    }
    /* fork() kthen 0 per procesin femije */
    if ((pid = fork()) < 0) {
        printf("Deshtoi fork per kete proces\n");
        exit(0);
    }
    /* nese pid eshte zero atehere ky eshte procesi femije */
    if (pid == 0) {
        /* Procesi femije mbyll skajet qe nuk nevojiten */
        close(fd[P1_READ]);
        close(fd[P1_WRITE]);
        int z;
        
        pid = getpid();
        printf("Procesi femije me pid %d: duke derguar te procesi prind\n", pid);
        
        /* dergon vlerat te prindi */
        int data [5] = { 6, 7, 8, 9, 10 };
        if (write(fd[P2_WRITE], &data, sizeof(int)*5) == -1) {
            printf("Procesi femije deshtoi dergimin e vlerave te procesi prind\n");
            exit(0);
        }
        
        /* tani pret per pergjigjen */
        int buf [5] = {};
        len = read(fd[P2_READ], &buf, sizeof(int)*5);
        for (z = 0; z < 5; z++) {
            printf("\nElementi i pranuar nga procesi femije eshte: %d\n ",buf[z]);
        }
        if (len < 0) {
            printf("Procesi femije deshtoi leximin e vleres nga pipe\n");
            exit(0);
        }
        
        /* mbyllja e skajeve */
        close(fd[P2_READ]);
        close(fd[P2_WRITE]);
        
        return EXIT_SUCCESS;
    } else {
        /* Procesi prind mbyll skajet e panevojshme */
        close(fd[P2_READ]);
        close(fd[P2_WRITE]);
        
        int k;
        int childPid = pid;
        pid = getpid();
        
        /* dergo nje vlere te procesi femije */
        printf("Procesi prind me pid %d: duke derguar te procesi femije\n", pid);
        int data[5] = { 1, 2, 3, 4, 5 };
        sleep(2);
        if(write(fd[P1_WRITE], &data, sizeof(int)*5) == -1) {
            perror("Procesi prind deshtoi dergimin e vlerave te procesi femije\n");
            exit(0);
        }
        sleep(2);
        
        /* tani pritje per pergjigje */
        int buf [5] = {};
        len = read(fd[P1_READ], &buf, sizeof(int)*5);
        for (k = 0; k < 5; k++) {
            printf("\nElementi i pranuar nga procesi prind eshte %d\n ",buf[k]);
        }
        kill(childPid, SIGKILL);
        if (len < 0) {
            perror("Procesi prind deshtoi leximin e vleres nga pipe\n");
            exit(0);
        }
        
        /* mbyllja e skajeve */
        close(fd[P1_READ]);
        close(fd[P1_WRITE]);
        
        /* kill procesin femije */
        exit(0);
    }
    return 0;
}
