// a10f6.c

#include <stdio.h>
#include "genlib.h"
#include "simpio.h"
void ReadData(int r, int c, double pin[r][c]);
double findMax(int r, int c, double pin[r][c]);

main()
{   printf("arithmos tmimatwn: ");
    int classes = GetInteger();
    printf("arithmos mathitwn: ");
    int students = GetInteger();

    double grades[classes][students];
    ReadData(classes,students,grades);

    double max = findMax(classes,students,grades);
    printf("\n%lf\n",max);

    return 0;
}

void ReadData(int r, int c, double pin[r][c]) {
    int i,j;
    for (i=0;i<r;i++) {
        printf("TMHMA %d \n", i);
        for (j=0;j<c;j++){
         printf("DWSE BA8TMOYS %d MA8HTH: ", j);
            pin[i][j]=GetReal();
        }
    }
}

double findMax(int r, int c, double pin[r][c]) {
    int i,j;
    double max;
    max=pin[0][0];
    for (i=0;i<r;i++) {
        for (j=0;j<c;j++)
        if (max<pin[i][j])
            max=pin[i][j];
    }
    return max;
}




