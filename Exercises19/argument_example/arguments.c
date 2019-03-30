#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>

#define P1_READ     0
#define P2_WRITE    1
#define P2_READ     2
#define P1_WRITE    3

#define NUM_PIPES   2

void usage() {
    printf("Perdorimi ./arguments -n -t xarg\n");
}

void noFirstArgument() {
    printf("missing option -n \n");
}

void noSecondArgument() {
    printf("missing option -t \n");
}

int main(int argc, char *argv[])
{
    int nOption = 0;
    int tOption = 0;
    int opt;
    int timeSec;
    char *nArgument;
    
    while ((opt = getopt(argc, argv, "nt:")) != -1) {
        switch (opt) {
            case 'n':
                nOption++;
                nArgument = optarg;
                printf("nArg: %s\n",nArgument);
                break;
            case 't':
                tOption++;
                timeSec = atoi(optarg);
                printf("nsecs=%d\n", timeSec);
                break;
            default:
                usage();
                exit(0);
                break;
        }
    }
    
    if (nOption != 1) { //Exactly one
        noFirstArgument();
        exit(0);
    }
    
    if (tOption != 1) {
        printf("option -t nuk eshe dhene ose me shume se nje here\n");
        exit(0);
    }
    
    if (tOption > 1) { // maximum 1 time
        printf("option -t maximum 1 time \n");
        exit(0);
    }
    
    return 0;
}
