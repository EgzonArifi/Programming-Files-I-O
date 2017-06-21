/*
 Solved problems Detyra 2
 */

#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <stdbool.h>
#include <string.h>

void usage() {
    printf("arkivo [-c shkallakomprimimit | -n] arkiva fajlli1 fajlli2 fajlli3...\n");
    exit(1);
}
void compress() {
    printf("Success\n");
    exit(1);
}
int main(int argc, char * argv[]) {
    
    int option;
    int optcnt = 0;
    int flagC = 0;
    int flagN = 0;
    int shkalla = 3;
    while ((option = getopt(argc, argv, "c:n")) != -1) {
        optcnt++;
        switch (option) {
            case 'c':
                flagC++;
                if (flagC > 1) {
                    usage();
                }
                int shkalla = atoi(optarg);
                printf("Shkalla e komprimimit %d\n",shkalla);
                if (shkalla < 1 || shkalla > 5 || !shkalla) {
                    usage();
                }
                break;
            case 'n':
                flagN++;
                if (flagN > 1) {
                    usage();
                }

                break;
            default:
                usage();
                break;
        }
    }
    
    if (flagC == 0 && flagN == 0) {
        usage();
    }
    
    int argmunets = argc-optcnt-2;
    printf("optind %d\n",optind);
    if (argmunets > 3) {
        usage();
    }

    compress();
    
    return 0;
}