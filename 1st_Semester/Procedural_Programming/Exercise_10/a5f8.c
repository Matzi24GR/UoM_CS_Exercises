#include <stdio.h>
#include "simpio.h"

typedef struct {
    int id;
    char name[16];
    long sales;
    int area;
} salesmanT;

char *city[] = {"Thes/niki", "Athens", "Volos","Hrakleio"};

void readData(salesmanT salesmen[],int N);

long calcData(salesmanT salesmen[],int N,long perArea[4]);

void printData(long perArea[4],long total);

int main() {
    printf("Pwlhtes: ");
    int count = GetInteger();
    salesmanT salesmen[20];

    readData(salesmen,count);

    long perArea[4];
    long total = calcData(salesmen,count,perArea);

    printData(perArea,total);

    return 0;
}

void readData(salesmanT salesmen[],int N) {
    for (int i=0;i<N;i++) {
        printf("Kwdikos: ");
        salesmen[i].id = GetInteger();
        printf("Epwnumo: ");
        gets(salesmen[i].name);
        printf("Pwlhseis: ");
        salesmen[i].sales = GetLong();
        printf("Perioxh: ");
        salesmen[i].area = GetInteger();
    }
}

long calcData(salesmanT salesmen[],int N,long perArea[4]) {
    for (int i=0;i<4;i++) perArea[i] = 0;
    for (int i=0;i<N;i++) perArea[(salesmen[i].area)-1]+= salesmen[i].sales;
    long total=0;
    for (int i=0;i<4;i++) total+=perArea[i];
    return total;
}

void printData(long perArea[4],long total) {
    printf("%11s%13s\n","PERIOXH","SYN.PWLHSEWN");
    for (int i=0;i<24;i++) printf("-");
    printf("\n");
    for (int i=0;i<4; i++) printf("%11s%13ld\n",city[i],perArea[i]);
    for (int i=0;i<24;i++) printf("-");
    printf("\n");
    printf("%11s%13ld\n","SYNOLO:",total);
}
