#include <stdio.h>
#include "simpio.h"

#define step1 12
#define step2 15
#define step3 20
#define step4 30

#define pagio1_2 20
#define pagio3 100

#define Vat 0.18

int main() {

    printf("Dwse ton kwdiko kathgorias timologiou: ");
    int type = GetInteger();
    printf("Dwse thn parousa endeixh toy metrhth: ");
    long CurrentReading = GetLong();
    printf("Dwse thn prohgoumenh endeixh toy metrhth: ");
    long PreviousReading = GetLong();

    long cons = CurrentReading - PreviousReading;
    //------------------------------------------------
    long cost;
    if (cons <=200) cost = cons*step1;
    else if (cons<= 500) cost = 200*step1 + (cons-200)*step2;
    else if (cons<= 1500) cost = 200*step1 + 300*step2 + (cons-500)*step3;
    else cost = 200*step1 + 300*step2 + 1000*step3 + (cons-1500)*step4;
    //-------------------------------------------------
    int pagio;
    switch(type) {
        case 1:case 2:
            pagio = pagio1_2;
            break;
        case 3:
            pagio = pagio3;
            break;
    }
    //-------------------------------------------------
    double costEuro = cost/100.0;
    double VatCost = (costEuro + pagio)*Vat;
    //-------------------------------------------------
    double finalCost = costEuro + pagio + VatCost;
    //-------------------------------------------------
    printf("katanalwsh reumatos se monades: %d\n",cons);
    printf("Axia reumatos(cent): %d\n",cost);
    printf("Pagio(eyro): %d\n", pagio);
    printf("FPA(euro): %g\n", VatCost);
    printf("Synoliko poso plhromhs(euro): %g", finalCost);

    return 0;
}
