#include <stdio.h>
#include "simpio.h"

int main() {

    long Taxes[10][3] = {   { 10000,   0,      0},
                            { 39000,  18,   5220},
                            { 49000,  21,   7320},
                            { 59000,  24,   9720},
                            { 85000,  28,  17000},
                            {100000,  33,  21950},
                            {120000,  38,  29650},
                            {150000,  43,  42450},
                            {170000,  49,  52250},
                            {     0,  50,      0}   };

    //for (int i=0;i<10;i++) {for (int j=0;j<3;j++) printf("%d   ",Taxes[i][j]);printf("\n");}

    long income = GetLong();

    long tax = 0;
    printf("%ld Euro\n",income);
    int i = 1;
    while (i<10) {
        if (income <= Taxes[i][0] && income >10000) {
            tax = Taxes[i-1][2];
            tax += (income-Taxes[i-1][0])*Taxes[i][1]/100;
            printf("%ld Euro\n", Taxes[i-1][2]);
            printf("%ld Euro\n", (income-Taxes[i-1][0])*Taxes[i][1]/100);
            printf("%ld Euro\n", tax);
            break;
        } else if(i==9 && income >10000) {
            tax = Taxes[8][2];
            tax += (income-Taxes[8][0])*Taxes[9][1]/100;
            printf("%ld Euro\n", Taxes[8][2]);
            printf("%ld Euro\n", (income-Taxes[8][0])*Taxes[9][1]/100);
            printf("%ld Euro\n", tax);
            break;
        }else i++;
    }

    if (income <= 10000) {
        tax = 0;
        printf("%ld Euro\n", 0);
        printf("%ld Euro\n", 0);
        printf("%ld Euro\n", tax);
    }


    return 0;
}
