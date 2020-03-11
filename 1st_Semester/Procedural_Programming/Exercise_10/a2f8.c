#include <stdio.h>
#include "simpio.h"

typedef struct {
    int id;
    char name[25];
    int size;
    int radiators;
    double heatCost;
    double otherCost;
    double total;
} rentalT;

rentalT readRentals(rentalT rentals[]);
void calcRentals(rentalT rentals[],rentalT total);
void printRentals(rentalT rentals[],rentalT total);

int main() {
    rentalT rentals[20];
    rentalT total = readRentals(rentals);

    calcRentals(rentals,total);
    printRentals(rentals,total);

    return 0;
}

rentalT readRentals(rentalT rentals[]) {
    rentalT total;
    total.size=0;
    total.radiators=0;

    printf("Plhthos enoikwn: ");
    total.id = GetInteger();

    printf("Dwse to poso thermanshs: ");
    total.heatCost = GetReal();

    printf("Dwse to poso koinoxrhstwn: ");
    total.otherCost = GetReal();

    for (int i=1;i<=total.id;i++) {
        rentals[i].id = i;

        printf("Dwse to onomateponymo: ");
        gets(rentals[i].name);

        printf("Dwse ta t.m: ");
        rentals[i].size = GetInteger();
        total.size+= rentals[i].size;

        printf("Dwse tis fetes: ");
        rentals[i].radiators = GetInteger();
        total.radiators+= rentals[i].radiators;
    }
    total.total = total.heatCost + total.otherCost;
    return total;
}

void calcRentals(rentalT rentals[],rentalT total){
    for (int i=1;i<=total.id;i++) {
        rentals[i].heatCost= (total.heatCost/total.radiators)*rentals[i].radiators;
        rentals[i].otherCost= (total.otherCost/total.size)*rentals[i].size;
        rentals[i].total = rentals[i].heatCost + rentals[i].otherCost;
    }
}

void printRentals(rentalT rentals[],rentalT total) {
    printf("%3s%26s%5s%6s%12s%12s%12s\n","A/A","ONOMATEPWNYMO","T.M.","FETES","POSO THERM.","POSO KOIN.","SYNOLO");
    for (int i=0;i<76;i++) printf("-");
    printf("\n");
    for (int i=1;i<=total.id;i++) printf("%3d%26s%5d%6d%12.2lf%12.2lf%12.2lf\n",
                                        rentals[i].id,
                                        rentals[i].name,
                                        rentals[i].size,
                                        rentals[i].radiators,
                                        rentals[i].heatCost,
                                        rentals[i].otherCost,
                                        rentals[i].total
                                        );
    for (int i=0;i<76;i++) printf("-");
    printf("\n");
    printf("%-29s%5d%6d%12.2lf%12.2lf%12.2lf","SYNOLA:",total.size,total.radiators,total.heatCost,total.otherCost,total.total);
}

