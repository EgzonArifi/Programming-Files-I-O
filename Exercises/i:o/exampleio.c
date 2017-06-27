#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#include <stdbool.h>

#define kFileName "file_to_write"
int main(int argc, char * argv[]) {
    FILE *dataFile;
    char ch;
    
    /* Writing something */
    if ((dataFile = fopen(kFileName,"a")) == NULL) {
        printf("Error while writing in file\n");
        exit(0);
    }
    char sentence[] = "This is a test\n";
    fwrite(sentence, strlen(sentence), 1, dataFile);
    fclose(dataFile);
    
    printf("Success\n");
    
    /* Readinf from the file */
    if ((dataFile = fopen(kFileName,"r")) == NULL) {
        printf("Error while reading from file\n");
        exit(0);
    }
    
    /* character read */
    printf("Reading for each character\n");
    while ((ch = fgetc(dataFile)) != EOF) {
        printf("%c",ch);
    }
    printf("\n");
    fclose(dataFile);
    return 0;
}