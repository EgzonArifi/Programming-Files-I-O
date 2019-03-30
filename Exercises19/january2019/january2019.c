#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void usage() {
    printf("Usage: ./january2019 [-d] [-n]\n");
    exit(0);
}

int isDivisor(int d, int n, int *dN) {
    *dN = n;
    
    if ((d % n) == 0) {
        return 1;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    
    //Direkt
    int dN;
//    printf("A jane te plotpjestueshem 6 dhe 3:  %d\n", isDivisor(6, 3, &dN));
//    printf("pjestuesi: %d\n", dN);
    
    //Me argumente
    int opt;
    int optcnt = 0;
    int dFlag = 0;
    int nFlag = 0;
    int d;
    int n;
    
    while ((opt = getopt(argc, argv, "d:n:")) != -1) {
        optcnt++;
        switch (opt) {
            case 'd':
                dFlag++;
                if (dFlag > 1) { // Nese perseritet me shume se njehere
                    usage();
                }
                d = atoi(optarg);
                
                if (!d) {
                    printf("d nuk eshte definuar");
                    exit(0);
                }
                break;
            case 'n':
                nFlag++;
                if (nFlag > 1) { // Nese perseritet me shume se njehere
                    usage();
                }
                
                n = atoi(optarg);
                if (n == 0 || !n) {
                    printf("Error me 0 ose nuk eshte definuar");
                    exit(0);
                }
                break;
            default:
                usage();
                break;
        }
    }
    
    if (dFlag == 0 && nFlag == 0) {
        usage();
    }
    
    int arguments = argc-optcnt-1;
    if (arguments != 2) {
        usage();
    }
    
    printf("-------------------------------\n");
    printf("A jane te plotpjestueshem %d dhe %d:  %d\n", d, n, isDivisor(d, n, &dN));
    printf("pjestuesi: %d\n", dN);
  
    return 0;
}
