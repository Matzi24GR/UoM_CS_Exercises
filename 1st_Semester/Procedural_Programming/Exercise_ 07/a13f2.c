#include <stdio.h>
#include "simpio.h"

#define cost 0.7

int main() {

    printf("Dose kafedes: ");
    int cups = GetInteger();

    if (cups > (int) 5/cost) { //  8 kai pano dhladh
        printf("den ftanoun ta xrhmata gia tosous kafedes");
    } else {

        double change = 5-(cost*cups);
        printf("\n%g\n",change);

        int coin2 = (int) change /2;
        change-= coin2*2;
        int coin1 = (int) change /1;
        change-= coin1*1;
        int coin50 = (int) (change /0.5);
        change-= coin50*0.49999;
        int coin20 = (int) (change /0.2);
        change-= coin20*0.19999;
        int coin10 = (int) (change /0.1);
        change-= coin10*0.99999;

        printf("Resta\n");
        printf("Kermata 2E :%d\n",coin2);
        printf("Kermata 1E :%d\n",coin1);
        printf("Kermata 50L :%d\n",coin50);
        printf("Kermata 20L :%d\n",coin20);
        printf("Kermata 10L :%d",coin10);
    }

    return 0;
}
