/*
 Solved problems Detyra 2
 */

#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <stdbool.h>

void usage(){
    printf("cancelredeyes [-o] [-s sensivity] pic\n");
    exit(1);
}

int main(int argc, char * argv[]) {
    
    int option;
    int flago = 0;
    int flags = 0;
    while ((option = getopt(argc, argv, "s:o")) != -1) {
        switch (option) {
            case 'o':
                flago++;
                if (flago > 1) {
                    usage();
                }
                
                break;
            case 's':
                flags++;
                if (flags > 1) {
                    usage();
                }
                int intensity =  atoi(optarg); //https://stackoverflow.com/a/16573360/4729736
                if (intensity < 0 || intensity > 999) {
                    usage();
                }
                break;
            default:
                usage();
                break;
        }
    }
    return 0;
}