#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

main() {

    double letterCost;
    long greekLetterCount, foreignLetterCount;

    printf("Dwse ton arithmo epistolwn eswterikou: ");
    greekLetterCount = GetLong();

    printf("Dwse ton arithmo epistolwn exwterikou: ");
    foreignLetterCount = GetLong();

    letterCost = (greekLetterCount * 0.30) + (foreignLetterCount * 0.80);
    printf("To synoliko kostos apostolhs einai %g", letterCost);

}
