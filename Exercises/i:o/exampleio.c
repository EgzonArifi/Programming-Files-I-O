#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#include <stdbool.h>

#define kFileName "file_to_write"
int main(int argc, char * argv[]) {
    FILE *dataFile;
    
    /* Writing something */
    if ((dataFile = fopen(kFileName,"a")) == NULL) {
        printf("Error while writing in file\n");
        exit(0);
    }
    char sentence[] = "This is a test\n";
    fwrite(sentence, strlen(sentence), 1, dataFile);
    
    printf("Success\n");
    
    return 0;
}