#include <stdio.h>
#include <stdlib.h>

#define MAXBUFLEN 1000000

FILE *dataFile;

int main(int argc, char * argv[]) {
    
    char source[MAXBUFLEN + 1];
    FILE *fp = fopen(argv[1], "r");
    size_t newLen;
    
    //Check number of arguments
    if (argc != 3) {
        printf("Wrong number of arguements\n");
        return 0;
    }
    
    /* Read data from file */
    if (fp != NULL) {
        newLen = fread(source, sizeof(char), MAXBUFLEN, fp);
        if ( ferror( fp ) != 0 ) {
            fputs("Error reading file\n", stderr);
        } else {
            source[newLen++] = '\0';
        }

        fclose(fp);
    } else {
        printf("Failed to read file\n");
        return 0;
    }
    
    /* Write your buffer to disk. */
    FILE *pFile = fopen(argv[2],"a");
    
    if (pFile){
        fwrite(source, newLen, 1, pFile);
        puts("Wrote to file!\n");
    }
    else{
        puts("Something wrong writing to File.\n");
    }
    
    fclose(pFile);
    
    return 0;
}
