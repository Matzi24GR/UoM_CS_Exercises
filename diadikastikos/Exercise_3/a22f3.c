#include <stdio.h>
#include "simpio.h"

int main() {

    printf("Dwse arithmo: ");
    int x = GetInteger();

    printf("H fthinousa akolouthia einai: %d",x);
    for (x--;x>=0;x--) {
        printf(",%d",x);
    }

    return 0;
}
