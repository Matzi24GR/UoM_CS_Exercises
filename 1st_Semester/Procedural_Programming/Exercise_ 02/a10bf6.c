// a10f6.c

#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

#define COLUMNS 15
void ReadData(int r, int c, double pin[r][c]);
double findMax(int r, int c, double pin[r][c]);
void findMaxRowCol(int r, int c, double pin[r][c], int *row,int *col);
void findMaxRow(int r, int c, double pin[r][c], double maxArray[r]);
void printArray(int r, double array[r]);

int main() {   printf("arithmos tmimatwn: ");
    int classes = GetInteger();
    printf("arithmos mathitwn: ");
    int students = GetInteger();

    double grades[classes][students];
    ReadData(classes,students,grades);

    double max = findMax(classes,students,grades);
    printf("\n%lf\n",max);

    int maxClass, maxStudent;
    findMaxRowCol(classes,students,grades,&maxClass,&maxStudent);
    printf("\n%lf sto %do tmima apo ton %do mathiti\n",max,maxClass,maxStudent);

    double maxArray[classes];
    findMaxRow(classes,students,grades,maxArray);
    printArray(classes,maxArray);


    return 0;
}

void ReadData(int r, int c, double pin[r][c]) {
    for (int i=0;i<r;i++) {
        printf("TMHMA %d \n", i);
        for (int j=0;j<c;j++){
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

void findMaxRowCol(int r, int c, double pin[r][c], int *row,int *col) {
    int i,j;
    double max;
    max=pin[0][0];
    for (i=0;i<r;i++) {
        for (j=0;j<c;j++)
            if (max<pin[i][j]) {
                max=pin[i][j];
                *row = i;
                *col = j;
            }
    }
}

void findMaxRow(int r, int c, double pin[r][c], double maxArray[r]) {
    int i,j;
    double max;
    for (i=0;i<r;i++) {
        max=pin[i][0];
        for (j=0;j<c;j++) {
            if (max<pin[i][j])
                max=pin[i][j];
        }
        maxArray[i] = max;
    }
}

void printArray(int r, double array[r]) {
    for (int i=0;i<r;i++)   printf("\n%lf\n", array[i]);
}
