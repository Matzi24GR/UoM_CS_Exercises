#include <stdio.h>
#include "simpio.h"


int main() {

    long N = GetLong(),a=1,b=0;
    printf("%d\n",b);
    printf("%d\n",a);
    for (int i=3; i <= N; i++) {
        long F = a+b;
        printf("%d\n",F);
        b = a;
        a = F;
    }

    return 0;
}


