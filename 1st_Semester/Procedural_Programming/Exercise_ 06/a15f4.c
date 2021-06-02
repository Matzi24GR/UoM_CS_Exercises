#include <stdio.h>
#include <simpio.h>
#define dollars  0.89
#define lira  0.618
#define fragko  1.5465
#define candollar  1.3565
#define yen   109.22

int Menu();
double Convert(int,double);


int main (){
    int choice= Menu();
    while (choice != 6) {
        printf("%f\n",Convert(choice,GetReal()));
        choice = Menu();
    }
    return 0;

}
int Menu(){
    printf("1. Metetroph se dollaria\n2. Metatroph se lires\n3. Metatroph se fraga Elbetias\n4. Metatroph se dollaria Canada\n5. Metatroph se gien\n6. Exodos\n");
    return GetInteger();

}
double Convert(int choice, double euro){
    switch (choice){
    case 1:
        return euro/dollars;
        break;
    case 2:
        return euro/lira;
        break;
    case 3:
        return euro/fragko;
        break;
    case 4:
        return euro/candollar;
        break;
    case 5:
        return euro/yen;
        break;
    }

}
