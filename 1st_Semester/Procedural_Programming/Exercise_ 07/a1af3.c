#include <stdio.h>
#include "simpio.h"
#include <math.h>

#define limit 160000
#define rate 0.07

int main() {

    long years=0,cars = 80000;


    while (cars <= limit) {
        years++;
        cars = ceil(cars*(1+rate));
    }

    printf("%d\n%d",years,cars);

    return 0;
}
