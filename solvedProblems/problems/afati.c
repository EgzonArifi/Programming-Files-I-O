/*
 Solved problems
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#include <stdbool.h>

//Detyra 1.1
int isDivisor(int d, int n) {
    if ((d % n) == 0) {
        return 1;
    }
    return 0;
}
//Detyra 1.2
int isDivisorByReference(int d, int n, int *fR) {
    *fR = n;
    if ((d % n) == 0) {
        return 1;
    }
    return 0;
}
//Detyra 1.2b

//Detyra 2

int main(int argc, char * argv[]) {

    //Detyra 1.1
    int d, n;
    printf("Jenpni numrat: ");
    scanf("%i %i",&d, &n);
    printf("a jane te plotepjestueshem?: %d\n", isDivisor(d, n));
    
    //Detyra 1.2
    int dR, nR, fR;
    printf("Jenpni numrat: ");
    scanf("%i %i", &dR, &nR);
    printf("a jane te plotepjestueshem?: %d\n", isDivisorByReference(dR, nR, &fR));
    printf("Faktori i pjestueshmerise: %d\n", fR);
    //Detyra 2
    
    return 0;
}
