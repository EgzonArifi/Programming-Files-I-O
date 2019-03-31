#include <stdio.h>

#define FILE_PATH "fileToWrite.txt"

int errorMessage() {
    printf("Something went wrong!");
    return 0;
}

void readChars() {
    
    //File Descriptor
    FILE *fd;
    
    //Open write, check for error
    if ((fd = fopen(FILE_PATH, "r")) == NULL) {
        errorMessage();
    }
    
    int c;
    
    while ((c = fgetc(fd)) != EOF) {
        printf("%c", c);
    }
    
    //Close connection, check for error
    if (fclose(fd) == EOF) {
        errorMessage();
    }
}

void writeChar() {
    //File Descriptor
    FILE *fd;
    
    //Open write, check for error
    if ((fd = fopen(FILE_PATH, "w")) == NULL) {
        errorMessage();
    }
    
    char string[] = "good bye\n";
    
    for (int i = 0; string[i] != '\0'; i++) {
        // Input string into the file
        // single character at a time
        fputc(string[i], fd);
    }
    
    //Close connection, check for error
    if (fclose(fd) == EOF) {
        errorMessage();
    }
}

#define LENGTH 255

void readLine() {
    
    //File Descriptor
    FILE *fd;
    
    //Open write, check for error
    if ((fd = fopen(FILE_PATH, "r")) == NULL) {
        errorMessage();
    }
    
    char pBuffer[LENGTH];
    
    while (fgets(pBuffer, LENGTH, fd) != NULL) {
        printf("%s", pBuffer);
    }
    
    //Close connection, check for error
    if (fclose(fd) == EOF) {
        errorMessage();
    }
}

void writeALine() {
    
    //File Descriptor
    FILE *fd;
    
    //Open write, check for error
    if ((fd = fopen(FILE_PATH, "w")) == NULL) {
        errorMessage();
    }
    
    char pWriteLine[] = "Ky eshte C programimi\n";
    
    fputs(pWriteLine, fd);
    
    //Close connection, check for error
    if (fclose(fd) == EOF) {
        errorMessage();
    }
}

void writeFormmatedLine() {
    
    //File Descriptor
    FILE *fd;
    
    //Open write, check for error
    if ((fd = fopen(FILE_PATH, "w")) == NULL) {
        errorMessage();
    }
    
    if (fprintf(fd, "%s %d\n", "We are", 2019) < 0) {
        errorMessage();
    }
    
    //Close connection, check for error
    if (fclose(fd) == EOF) {
        errorMessage();
    }
}

int main(int argc, char *argv[]) {
    
    //Ekzistojen 4 tipe te I/O funksioneve
    
    //Per procesim te shenjave (char)
    writeChar();
    readChars();
    
    //Per procesim te rreshtave
    writeALine();
    readLine();
    
    //Per procesim binar
    
    //Per procesim te formatuar
    writeFormmatedLine();
    readLine();
    
    return 0;
}
