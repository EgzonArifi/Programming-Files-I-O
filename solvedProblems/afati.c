/*
 Solved problems
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#include <stdbool.h>

//Detyra 1.1
bool isValid(int muaji, int viti) {
    if (muaji < 1 || muaji > 12) {
        return false;
    }
    if (viti < 1900 || viti > 2100) {
        return false;
    }
    return true;
}

//Detyra 1.2a
struct TData
{
    unsigned int muaji;
    unsigned int viti;
};
struct TAutomobili
{
    char prodhuesi[80];
    char tipi[80];
    struct TData *dataProdhimit;
    unsigned int kilometrat;
    float vleraShitse;
};

//Detyra 1.2b
struct TAutomobili initializeAutomobilet(char prodhuesi[80], char tipi[80], unsigned int kilometrat,float vleraShitse, unsigned int muaji, unsigned int viti) {
    
    struct TAutomobili automobili;
    
    strcpy( automobili.prodhuesi, prodhuesi);
    strcpy( automobili.tipi, tipi);
    automobili.kilometrat = kilometrat;
    automobili.vleraShitse = vleraShitse;
    
    struct TData data;
    data.muaji = muaji;
    data.viti = viti;
    
    automobili.dataProdhimit = &data;
    
    return automobili;
}
struct TAutomobili initializeAutomobilet1(struct TAutomobili *pAuto) {
    
    struct TAutomobili automobili;
    
    strcpy( automobili.prodhuesi, pAuto->prodhuesi);
    strcpy( automobili.tipi, pAuto->tipi);
    automobili.kilometrat = pAuto->kilometrat;
    automobili.vleraShitse = pAuto->vleraShitse;
    
    struct TData data;
    data.muaji =  pAuto->dataProdhimit->muaji;
    data.viti = pAuto->dataProdhimit->viti;

    automobili.dataProdhimit = &data;
    
    return automobili;
}
//Detyra 2
void usage(){
    printf("arkivo [-c shkalla | -n] arkiv fajli1 [fajlli2 fajliir ...]\n");
    exit(1);
}

int main(int argc, char * argv[]) {

    //Detyra 1.1
    int muaji, viti;
    printf("Jepni muajin dhe vitin: ");
    scanf("%i %i", &muaji, &viti);
    printf("\nis valid %d\n",isValid(muaji,viti));
    
    //Detyra 1.2b
    struct TAutomobili auto1, auto2;
    auto1 = initializeAutomobilet("audi", "A4", 8200, 9400.99, 4, 2010);
    printf("\nAuto1 :%s \n",auto1.tipi);
    printf("\nData auto1: %d %d\n", auto1.dataProdhimit->muaji, auto1.dataProdhimit->viti);
    
    auto2 = initializeAutomobilet("bmw", "320", 2400, 4299.90, 2, 2004);
    printf("\nAuto2 :%s \n",auto2.tipi);
    printf("\nData auto2: %d %d\n", auto2.dataProdhimit->muaji, auto2.dataProdhimit->viti);
    
    struct TAutomobili pAuto;
    pAuto = initializeAutomobilet1(&auto2);
    printf("\npAuto :%s \n",pAuto.tipi);
    printf("\npAuto Data auto1: %d %d  \n", pAuto.dataProdhimit->muaji, pAuto.dataProdhimit->viti);

    //Detyra 2
    if(argc<3) {
        usage();
    }
    
    int option;
    int shkalla=3;
    int flagc=0;
    int flagn=0;
    int komprimo=1;
    while ((option=getopt(argc,argv,"c:n"))!=-1) {
        switch(option)
        {
            case 'c':
                if(flagc) {
                    usage();
                } else {
                    shkalla=optarg[0]-'0';
                    if((shkalla>5||shkalla<1) || (strlen(optarg) > 1)) {
                        usage();
                    }
                    flagc++;
                    flagn++;
                }
                break;
            case 'n':
                if (flagn) {
                    usage();
                } else {
                    printf("%s\n",argv[optind]);
                    komprimo=0;
                    flagc++;
                    flagn++;
                }
                break;
            default:
                usage();
        }
    }
    
    if(!((argc-(optind-1))>2 && (argc-(optind-1))<1026)) {
        usage();
    }
    return 0;
}
