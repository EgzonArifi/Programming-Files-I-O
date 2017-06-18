/*
 Solved problems Detyra 2
 */

#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <stdbool.h>
#include <string.h>

void usage() {
    printf("cancelredeye [-o] [-s sensivity] pic\n");
    exit(1);
}
void done() {
    printf("Success\n");
    exit(1);
}
int main(int argc, char * argv[]) {
    
    int option;
    int optcnt = 0;
    int flago = 0;
    int flags = 0;
    while ((option = getopt(argc, argv, "s:o")) != -1) {
        optcnt++;
        switch (option) {
            case 'o':
                flago++;
                if (flago > 1) {  //nese eshte perserit ma shume se nje here throw
                    usage();
                }
                
                break;
            case 's':
                flags++;
                if (flags > 1) { //nese eshte perserit ma shume se nje here throw
                    usage();
                }
                int intensity =  atoi(optarg); //https://stackoverflow.com/a/16573360/4729736
                if (intensity < 0 || intensity > 999 || !intensity) { //ose strlen(optarg) > 3 check me kon 0>intensity>999
                    usage();
                }
                break;
            default:
                usage();
                break;
        }
    }
    
    if (flago == 0 && flags == 0) {// nese nuk jane jep -o -s
        if (argc != 2) { //me i pas sakt 2 argumente, i pari eshte ./cancelredeye edhe masnej emri i fotos
            usage();
        }
        done();
    }
    
    int argmunets = argc-optcnt-1;
    if (argmunets != 2) {//check nese jon sakt 2 te dhena per -s dmth -s 80 emriFajllit.jpg
        usage();
    }
    
    done();
    
    return 0;
}