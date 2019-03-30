#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "ArgProcess.h"

int main(int argc, char *argv[]) {

    int isValid = validateArguments(argc, argv);
    if (isValid == 0) {
        printf("Invalid\n");
        return 0;
    }
    
    printf("Valid\n");

    return 0;
}
