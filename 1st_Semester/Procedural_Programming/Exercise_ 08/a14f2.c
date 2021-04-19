#include <stdio.h>
#include "simpio.h"

int main() {

    printf("Dose ypsos: ");
    double height = GetReal();

    printf("Dose baros: ");
    double weight = GetReal();

    double BMI = weight/(height*height);

    if (BMI<18.5) printf("Lipovaris");
    else if (BMI<25) printf("Kanonikos");
    else if (BMI<30) printf("Yperbaros");
    else printf("Paxusarkos");

    return 0;
}
