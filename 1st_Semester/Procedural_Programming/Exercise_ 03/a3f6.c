#include <stdio.h>

void swap(int *x, int *y);

int main() {
    int a, b, c;
    scanf("%d",&a);
    scanf("%d",&b);
    scanf("%d",&c);

    if (a>b) swap(&a,&b);
    if (b>c) swap(&b,&c);
    if (a>b) swap(&a,&b);
    if (b>c) swap(&b,&c);
    if (a>b) swap(&a,&b); // kalou kakou
    if (b>c) swap(&b,&c);

    printf("%d %d %d\n",a,b,c);
    return 0;
}

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}
