#include <stdio.h>
#include "string.h"
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#define kFileLocation "Datas"
#define MAXBUFLEN 1000000

FILE *dataFile;

void writeToFile() {
    char sentence[1000];
    
    if((dataFile = fopen(kFileLocation,"w")) == NULL)
    {
        printf("Error!\n");
        exit(1);
    }
    
    printf("Enter something:  ");
    gets(sentence);
    
    fprintf(dataFile,"%s",sentence);
    fclose(dataFile);
}

void readFromFile() {
    char ch;
    
    if((dataFile = fopen(kFileLocation,"r")) == NULL)
    {
        printf("Error!\n");
        exit(1);
    }
    
    printf("You wrote this: ");
    while ((ch = fgetc(dataFile)) != EOF)
    {
        printf("%c",ch);
    }
    
    fclose(dataFile);
}



int main(int argc, char * argv[]) {
    
    char source[MAXBUFLEN + 1];
    FILE *fp = fopen(argv[0], "r");
    size_t newLen ;
    if (fp != NULL) {
        newLen = fread(source, sizeof(char), MAXBUFLEN, fp);
        if ( ferror( fp ) != 0 ) {
            fputs("Error reading file", stderr);
        } else {
            source[newLen++] = '\0';
        }
        
        
        
        fclose(fp);
    }
    
    /* Write your buffer to disk. */
    FILE *pFile = fopen("DatasCopy","w");
    
    if (pFile){
        fwrite(source, newLen, 1, pFile);
        puts("Wrote to file!");
    }
    else{
        puts("Something wrong writing to File.");
    }
    
    fclose(pFile);
}

//int main (int argc, const char * argv[])
//{
//    int c;
//    
//    char sentence[1000];
//    if((dataFile = fopen(kFileLocation,"r")) == NULL)
//    {
//        printf("Error!\n");
//        exit(1);
//    }
//    while ((c == )) {
//        statements
//    }
//    
//    
//    
//    //Writing
//    writeToFile();
//    
//    //Reading
//    readFromFile();
//    
//  //  Tests Example
//    printf("\nmain() : argc: %d \n", argc);
//    int index = 0;
//    for (index = 0; index < argc; ++index) {
//        if ( strncmp( argv[index], "debug", 5) == 0) {
//            printf("PRGRAM DEBUG MODE\n");
//        } else if ( strncmp( argv[index], "-file", 5) == 0) {
//            printf("main() : PROGRAM READ FILENAME: %s\n", argv[index + 1]);
//        }
//    }
//    
//    
//    
//    //Exmaple
//    while ((c = getopt(argc, argv, "a:o")) != EOF) {
//        switch (c) {
//            case 'a':
//                printf("Opciome argument\n");
//                break;
//                
//            case 'o':
//                printf("Opcion pa argument\n");
//                break;
//                
//            case '?':
//                printf("Argument i pavleshem\n");
//                break;
//                
//            default:
//                break;
//        }
//    }
//    return 0;
//}
