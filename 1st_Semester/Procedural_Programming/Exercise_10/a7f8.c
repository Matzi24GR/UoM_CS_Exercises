#include <stdio.h>
#include "simpio.h"

typedef struct {
    int number;
    char type[20];
    int cc;
    char name[20];
    int days;
    float daily_rate;
    float price;
}   rentalCarT;

int getData(rentalCarT rentals[]);
float calcTotals(int size, rentalCarT rentals[size]);
rentalCarT findMax(int size, rentalCarT rentals[size]);
void printDetailed(int size, rentalCarT rentals[size]);

int main() {

    rentalCarT rentals[20];
    int count = getData(rentals);
    float total = calcTotals(count,rentals);
    rentalCarT maxCar = findMax(count,rentals);
    printDetailed(count,rentals);
    printf("%58s %-8.02f\n","Total", total);
    printf("Best car: %s %d rented for %.2f Euros.\n",maxCar.type,maxCar.cc,maxCar.price);
    return 0;
}

int getData(rentalCarT rentals[20]) {
    printf("Dose ton arithmo ton enoikiaseon: ");
    int count = GetInteger();
    for (int i=0;i<count;i++) {
        printf("\nDose ta stoixeia tis enoikiasis %d\n",i);
        rentals[i].number = i;
        printf("Dose marka: ");
        gets(rentals[i].type);
        printf("Dose kyvika: ");
        rentals[i].cc = GetInteger();
        printf("Dose onoma pelati: ");
        gets(rentals[i].name);
        printf("Dose imeres enoikiasis: ");
        rentals[i].days = GetInteger();
        printf("Dose timi ana imera: ");
        rentals[i].daily_rate = GetReal();
    }
    return count;
}

float calcTotals(int size, rentalCarT rentals[size]){
    float sum = 0;
    for (int i=0;i<size;i++) {
        rentals[i].price = rentals[i].days * rentals[i].daily_rate;
        sum+= rentals[i].price;
    }
    return sum;
}

rentalCarT findMax(int size, rentalCarT rentals[size]) {
    float max = 0;
    rentalCarT maxCar;
    for (int i=0;i<size;i++) {
        if (rentals[i].price>max) maxCar = rentals[i];
    }
    return maxCar;
}

void printDetailed(int size, rentalCarT rentals[size]) {
    printf("\n\n");
    printf("%-7s %-20s %-10s %-5s %-5s %-6s %-8s\n","Number","Name","Type","CC","Days","Price","Total");
    for(int i=1; i<=73; i++) printf("-");
    printf("\n");
    for (int i=0;i<size;i++) {
        printf("%-7d %-20s %-10s %-5d %-5d %-6.02f %-8.02f\n",
               rentals[i].number,
               rentals[i].name,
               rentals[i].type,
               rentals[i].cc,
               rentals[i].days,
               rentals[i].daily_rate,
               rentals[i].price
               );
    }
    for(int i=1; i<=73; i++) printf("-");
    printf("\n");
}
