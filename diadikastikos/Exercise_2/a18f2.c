#include <stdio.h>
#include "simpio.h"

int main() {

    printf("Dose milia: ");
    double miles = GetReal();
    printf("Dose litra: ");
    double litres = GetReal();

    double efficiency = litres/miles;

    if (efficiency<=0.9) printf("Poli xamili");
    else if (efficiency<=1.2) printf("Xamili");
    else if (efficiency<=1.8) printf("Kanoniki");
    else printf("Ypsili");

    return 0;
}
