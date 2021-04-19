#include <stdio.h>
#include "simpio.h"

int main() {

    printf("Dose theseis: ");
    int seats = GetInteger();

    printf("Dose epibates: ");
    int passengers = GetInteger();

    double percentage = (double)passengers/seats;

    if (percentage<0.30) printf("Zimia");
    else if (percentage>=0.50) printf("Kerdos");
    else printf("Kostos");

    return 0;
}
