#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

main(){

    int rate;
    long purchaseAmount;
    double profit, saleAmount;

    printf("Dwse thn katharh axia: ");
    purchaseAmount = GetLong();

    printf("Dwse to pososto kerdous: ");
    rate = GetInteger();

    profit = purchaseAmount * (rate / 100.0);
    printf("To kerdos einai %g", profit);

    printf("\n");

    saleAmount = purchaseAmount + profit;
    printf("To synoliko poso einai %g", saleAmount);

}
