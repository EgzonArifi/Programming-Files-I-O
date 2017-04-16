#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#include <stdbool.h>

#define kFileToWrite "StudentsFile"

FILE *dataFile;

void readStudentsFile() {
    char ch;
    
    if((dataFile = fopen(kFileToWrite,"r")) == NULL)
    {
        printf("Error!\n");
        exit(1);
    }
    printf("\nStudents List:\n[Emri Mbiemri Piket  Nota]\n\n");
    while ((ch = fgetc(dataFile)) != EOF)
    {
        printf("%c",ch);
    }
    printf("\n");
    fclose(dataFile);
}

void printWrongMessage() {
    printf("Wrong! Usage: studentiFile -add [Emri Mbiemri Piket  Nota] -l\n");
}

int main(int argc, char * argv[]) {
    
    bool isAddMode;
    bool isListMode;
    
    // Argument checking
    for (int index = 0; index <  argc; index++) {
        if ( strncmp( argv[index], "-add", 3) == 0) {
            printf("-Add MODE\n");
            isAddMode = true;
        } else if ( strncmp( argv[index], "-l", 1) == 0) {
            printf("-list MODE\n");
            isListMode = true;
        }
    }
    
    // Check number of arguments
    if (isAddMode && isListMode) {
        if (argc != 7) {
            printWrongMessage();
            return 0;
        }
    } else if (isAddMode) {
        if (argc != 6) {
            printWrongMessage();
            return 0;
        }
    } else if (isListMode) {
        if (argc != 2) {
            printWrongMessage();
            return 0;
        }
    } else {
        printWrongMessage();
        return 0;
    }
    
    // Write your buffer to disk.
    dataFile = fopen(kFileToWrite,"a");
    if (isAddMode) {
        for (int i = 2; i < 6; i++) {
            if (dataFile){
                fwrite(argv[i], strlen(argv[i]), 1, dataFile);
                printf("You wrote: %s\n",argv[i]);
            }
            else{
                printf("Something wrong writing to File.\n");
            }
            fwrite(" ", 1, 1, dataFile);
        }
        fwrite("\n", 2, 1, dataFile);
        fclose(dataFile);
    }
    
    if (isListMode) {
        readStudentsFile();
    }
    
}