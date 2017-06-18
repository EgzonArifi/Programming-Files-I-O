/*
 Solved problems
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#include <stdbool.h>

//Detyra 1.1
int isDivisor(int d, int n) {
    if ((d % n) == 0) {
        return 1;
    }
    return 0;
}
//Detyra 1.2
int isDivisorByReference(int d, int n, int *fR) {
    *fR = n;
    if ((d % n) == 0) {
        return 1;
    }
    return 0;
}
//Detyra 1.3a
enum { MAXNAME = 80 };


struct Animals
{
    char Name[MAXNAME];
    unsigned short Legs;
    unsigned int Weight;
    int Discovered;
};
//Detyra 1.3b
void initAnimal(char Name[MAXNAME], unsigned short Legs, unsigned int Weight, int Discovered,struct Animals *animalRef) {
    struct Animals animal;
    
    strcpy(animal.Name, Name);
    animal.Legs = Legs;
    animal.Weight = Weight;
    animal.Discovered = Discovered;
    
    *animalRef = animal;
}

int main(int argc, char * argv[]) {

    //Detyra 1.1
    int d, n;
    printf("Jenpni numrat: ");
    scanf("%i %i",&d, &n);
    printf("a jane te plotepjestueshem?: %d\n", isDivisor(d, n));
    
    //Detyra 1.2
    int dR, nR, fR;
    printf("Jenpni numrat: ");
    scanf("%i %i", &dR, &nR);
    printf("a jane te plotepjestueshem?: %d\n", isDivisorByReference(dR, nR, &fR));
    printf("Faktori i pjestueshmerise: %d\n", fR);
    
    //Detyra 1.3c
    struct Animals animal1, animal2;
    
    initAnimal("110kembeshi", 110, 3, 2008, &animal1);
    printf("Animal1 : Name:%s, Legs: %d, Weight: %d, Discovered: %d\n",animal1.Name, animal1.Legs, animal1.Weight, animal1.Discovered);
    
    initAnimal("OktopusGjigant", 7, 10000, -3000, &animal2);
    printf("Animal2 : Name:%s, Legs: %d, Weight: %d, Discovered: %d\n",animal2.Name, animal2.Legs, animal2.Weight, animal2.Discovered);
    
    return 0;
}
