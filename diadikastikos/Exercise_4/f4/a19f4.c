#include <stdio.h>
#include <simpio.h>
#include <math.h>

double calc(long);

int main() {
    double pi = calc(1000);
    printf("%f",pi);
    return 0;
}

double calc(long x) {
    if (x != 0) {
        //printf("%l\n",x);
        return calc(x-2)*( pow(x,2)/((x-1)*(x+1)) );
    } else {
        //printf("end\n");
        return 2;
    }
}
