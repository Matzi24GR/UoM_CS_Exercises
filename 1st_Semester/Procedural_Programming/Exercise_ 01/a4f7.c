#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "simpio.h"

int getNumber();
int main() {
    printf("Type a Positive Integer: ");
    int x =  getNumber();
    printf("L= ");
    int L = getNumber();

    char string[L+1];
    int num = x;
    int digits = 0;
    while(num != 0) {
        digits++;
        num /= 10;
    }
    for (int i = 0;i<L-digits;i++) string[i]='0';

    char stringN[digits+1];
    itoa(x,stringN,10);

    strcat(string,stringN);

    printf("%s",string);
    return 0;
}

int getNumber() {
    int x =  GetInteger();
    if (x<=0) getNumber();
    return x;
}
