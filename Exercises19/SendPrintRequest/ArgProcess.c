#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "ArgProcess.h"
#include <time.h>

#define usage_message "Usage: SendPrintRequest -f filename [-s #startPage -e #endPage] -p printerName\n"

void usage(char *message) {
    printf("%s",message);
}

int invalidArguments() {
    usage(usage_message);
    return 0;
}

char* getTimeStamp() {
    time_t T= time(NULL);
    struct  tm tm = *localtime(&T);
//    printf("System Date is: %04d-%02d-%02d\n",tm.tm_year+1900 , tm.tm_mon+1, tm.tm_mday);
//    printf("System Time is: %02d:%02d:%02d\n",tm.tm_hour, tm.tm_min, tm.tm_sec);
    char *timestamp;
    snprintf(timestamp, sizeof(timestamp), "%04d-%02d-%02d\n", tm.tm_year+1900 , tm.tm_mon+1, tm.tm_mday);
    printf("%s",timestamp);
    return timestamp;
}

char* getUsername() {
    //Username
    char *p=getenv("USER");
    if(p==NULL) return "";
    return p;
}

int validateArguments(int argc, char *argv[])
{
    int opt;
    int fFlag = 0;
    int sFlag = 0;
    int eFlag = 0;
    int pFlag = 0;
    char *fileName;
    char *printerName;
    
    while ((opt = getopt(argc, argv, "f:e:p:s:")) != -1) {
        switch (opt) {
            case 'f':
                fFlag++;
                printf("fFlag : %d\n", fFlag);
                fileName = optarg;
                break;
            case 'p':
                pFlag++;
                printf("pFlag : %d\n", pFlag);
                printerName = optarg;
                break;
            case 's':
                sFlag++;
                printf("sFlag : %d\n", sFlag);
                break;
            case 'e':
                eFlag++;
                printf("eFlag : %d\n", eFlag);
                break;
            default:
                return invalidArguments();
                break;
        }
    }
    
    if (fFlag != 1) {
        return invalidArguments();
    }
    
    if (pFlag != 1) {
        return invalidArguments();
    }
    
    //Username
    char *p=getenv("USER");
    if(p==NULL) return EXIT_FAILURE;
    printf("%s\n",p);
    
    //date time
    time_t T= time(NULL);
    struct  tm tm = *localtime(&T);
    printf("System Date is: %04d-%02d-%02d\n",tm.tm_year+1900 , tm.tm_mon+1, tm.tm_mday);
    printf("System Time is: %02d:%02d:%02d\n",tm.tm_hour, tm.tm_min, tm.tm_sec);
    
    printf("%s\n", getUsername());
    //file name
    printf("FileName %s\n", fileName);
    
    //printer name
    printf("PrinterName %s\n", printerName);
    
    return 1;
}
