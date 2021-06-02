#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

main() {

    double Vat, OrderCost;
    long ItemPrice, ItemCount;

    printf("Dwse thn timh temaxiou: ");
    ItemPrice = GetLong();

    printf("Dwse to pososto FPA: ");
    Vat = GetReal();

    printf("Dwse to plithos twn temaxiwn: ");
    ItemCount = GetLong();

    OrderCost = (ItemPrice * ItemCount) * (Vat+1);
    printf("To kostos ths paragelias einai %g", OrderCost);

}
