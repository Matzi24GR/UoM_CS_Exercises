#include <stdio.h>
#include "simpio.h"

int main() {

    double weeklySalary;

    printf("Dwse ton kwdiko: ");
    long id = GetLong();

    if (id >= 1000) {

        printf("Dwse ton ethsio mistho: ");
        double yearlySalary = GetReal();

        weeklySalary = yearlySalary / 52.0;

    } else {

        printf("Dwse tis wres ebdomadiaias ergasias: ");
        int workHours = GetInteger();
        printf("Dwse thn amoibh ana wra: ");
        double hourlySalary = GetReal();

        if (workHours > 40) {
            weeklySalary = (40*hourlySalary) + ( (workHours-40)*1.5*hourlySalary );
        } else {
            weeklySalary = workHours*hourlySalary;
        }

    }

    printf("H ebdomadiaia amoibh einai %g", weeklySalary);

    return 0;
}
