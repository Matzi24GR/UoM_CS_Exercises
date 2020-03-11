#include <stdio.h>
#include "simpio.h"

int main(){

    long x;
    long count=0, Sum=0;

    do {
        printf("Dwse ton bathmo: ");
        x = GetLong();
        count++;
        Sum+=x;
    } while (x != -1);

    count--;
    Sum++;

    if (count > 0) {
    double average = (double)Sum/count;
    printf("%d\n%d\n%g",count,Sum,average);
    }

    return 0;

}
