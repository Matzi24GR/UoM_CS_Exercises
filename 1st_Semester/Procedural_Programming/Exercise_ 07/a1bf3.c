#include <stdio.h>
#include "simpio.h"
#include <math.h>


int main() {

    printf("Dwse ton arxiko arithmo autokinhtvn: ");
    long cars = GetLong();

    printf("Dwse ton ethsio rythmo ayxhshs: ");
    double rate = GetReal();

    printf("Dwse to orio: ");
    long limit = GetLong();

    long years=0;


    while (cars <= limit) {
        years++;
        cars = ceil(cars*(1+rate));
    }

    printf("%d\n%d",years,cars);

    return 0;
}

