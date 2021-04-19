#include <stdio.h>
#include <math.h>
#include "simpio.h"

int main() {

    double temps[10][3];
    //double temps[10][3]={19, 3, 25, 13, 16, 17, 8, 18, 12, 1, 7, 2, 30, 28, 15, 4, 11, 14, 26, 10, 21, 20, 23, 6, 27, 29, 22, 5, 9, 24};
    for (int i=0; i<10;i++){
        for (int j=0; j<3;j++){
            temps[i][j] = GetReal();
        }
    }

    double natAvg = 0;
    for (int i=0; i<10;i++){
        for (int j=0; j<3;j++){
            natAvg+=temps[i][j];
        }
    }
    natAvg = natAvg/30;

    double avg[10];
    for (int i=0; i<10;i++){
            avg[i] = 0;
        for (int j=0; j<3;j++){
            avg[i]+=temps[i][j];
        }
        avg[i]=avg[i]/3;
    }

    double DiffNat[10][3];
    for (int i=0; i<10;i++){
        for (int j=0; j<3;j++){
            DiffNat[i][j]=fabs(temps[i][j]-natAvg);
        }
    }

    double maxDiff[10];
    for (int i=0; i<10;i++){
        maxDiff[i]=DiffNat[i][0];
        for (int j=1; j<3;j++){
            if (maxDiff[i]<DiffNat[i][j]) maxDiff[i]=DiffNat[i][j];
        }
    }

    printf("%4.1f\n",natAvg);
    for (int i=0; i<10;i++){
        printf("%4.1f %7.1f\n",avg[i],maxDiff[i]);
    }

    return 0;
}
