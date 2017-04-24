/*
 This program is used to store or list students information.
 The informations are stored in a file provided by user
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#include <stdbool.h>

/* File pointer */
FILE *dataFile;

/* A variable to check if list mode is first */
bool isListModeFirst;

/* Method used to print students file */
void readStudentsFile(char *fileName) {
    char ch;
    
    if((dataFile = fopen(fileName,"r")) == NULL) {
        printf("Error!\nThis file does not exist\n");
        exit(0);
    }
    printf("\nStudents List:\n[Emri Mbiemri Piket  Nota]\n\n");
    while ((ch = fgetc(dataFile)) != EOF) {
        printf("%c",ch);
    }
    printf("\n");
    fclose(dataFile);
}

/* Method to print wrong usage*/
void printWrongMessage() {
    printf("Wrong! Usage: ./myStudentsFile studentiFile -add [Emri Mbiemri Piket  Nota] -l\n");
}

/* Helper method to check index of argument to write */
int indexOfAddStartArgument() {
    if (isListModeFirst) {
        return 4;
    } else {
        return 3;
    }
}

int main(int argc, char * argv[]) {
    
    int ch;
    bool isAddMode = false;
    bool isListMode = false;
    int addOptionCount = 0;
    int listOptionCount = 0;
    int kNumberOfArgumentToWrite = 4;
    
    /* Options checking */
    int index;
    for (index = 0; index <  argc; index++) {
        if ( strncmp( argv[index], "-add", 4) == 0) {
            isAddMode = true;
            addOptionCount++;
            
        } else if ( strncmp( argv[index], "-l", 2) == 0) {
            listOptionCount++;
            isListMode = true;
        }
    }
    
    /* Check if there is no mode */
    if (!isAddMode && !isListMode) {
        printWrongMessage();
        return 0;
    }
    
    /* Check if list mode is before add mode */
    if ( strncmp( argv[2], "-l", 2) == 0) {
        isListModeFirst = true;
    } else {
        isListModeFirst = false;
    }
    
    /* Check if there are more than one -add */
    if (isAddMode && addOptionCount != 1) {
        printWrongMessage();
        return 0;
    }
    
    /* Check if there is max one -l */
    if (isListMode && listOptionCount > 1) {
        printWrongMessage();
        return 0;
    }
    
    if ((strncmp( argv[1], "-l", 2) == 0) || (strncmp( argv[1], "-add", 4) == 0)) {
        printf("wrong File name \n%s\n",argv[1]);
        printWrongMessage();
        return 0;
    }
    
    /* Check number of arguments */
    if (isAddMode && isListMode && argc != 8) {
        printWrongMessage();
        return 0;
    } else if (!isListMode && argc != 7) {
        printWrongMessage();
        return 0;
    }
    
    /* Opens the filename pointed to, by filename using the append mode */
    if((dataFile = fopen(argv[1],"a")) == NULL) {
        printf("Error while writing in file!\n");
        exit(1);
    }
    
    if (isAddMode) {
        /* Write data to disk */
        int i;
        for (i = indexOfAddStartArgument(); i < indexOfAddStartArgument() + kNumberOfArgumentToWrite; i++) {
            fwrite(argv[i], strlen(argv[i]), 1, dataFile);
            printf("You wrote: %s\n",argv[i]);
            fwrite(" ", 1, 1, dataFile);
        }
        fwrite("\n", 2, 1, dataFile);
        fclose(dataFile);
    }
    
    /* Print List of students from file */
    if (isListMode) {
        readStudentsFile(argv[1]);
    }
    
    return 0;
}