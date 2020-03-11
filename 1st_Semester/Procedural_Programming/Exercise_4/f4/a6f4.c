#include <stdio.h>
#include <simpio.h>

int MAX(int x,int y);
int MIN(int x,int y);


int main (){

    int x =GetInteger();
    int y =GetInteger();
    printf("%d\n",MAX(x,y));
    printf("%d\n",MIN(x,y));

    return 0;

}

int MAX(int x,int y) {
    if (x>y) {
        return x;
    } else {
        return y;
    }
}

int MIN(int x,int y) {
    if (x<y) {
        return x;
    } else {
        return y;
    }
}

