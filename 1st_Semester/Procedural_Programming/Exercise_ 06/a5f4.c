#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

int Sum_Cube(int);
bool IsArmStrong(int);
int Cube(int);

int main() {

    int i;
    for (i=1;i<=999;i++) {
        if (IsArmStrong(i)) printf("%d\n",i);
    }

    return 0;
}

bool IsArmStrong(int i) {
    return Sum_Cube(i)==i;
}

int Sum_Cube(int i){
    int d1 = i%10;
    int d2 = i/10%10;
    int d3 = i/100;
    return Cube(d1)+Cube(d2)+Cube(d3);
}

int Cube(int num){
    int product = 1;
    for (int i = 1; i<=3; i++) product *= num;
    return product;
}
