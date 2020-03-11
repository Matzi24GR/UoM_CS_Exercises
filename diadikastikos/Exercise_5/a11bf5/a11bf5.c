#include <stdio.h>
#include <math.h>
#include "genlib.h"
#include "simpio.h"

#define m 10
#define n 3


void   ReadData    (double temps[m][n]);
double getNatAvg   (double temps[m][n]);
void   getCityAvg  (double average[m], double temps[m][n]);
void   getDevNat   (double devnat[m][n], double temps[m][n], double natAvg);
void   getMaxDev   (double maxDev[m], double devnat[m][n]);
void   print       (double natAvg, double average[m],  double maxDev[m]);

int main() {

    double temps[m][n];
    ReadData(temps);

    double natAvg = getNatAvg(temps);

    double average[m];
    getCityAvg(average,temps);

    double devnat[m][n];
    getDevNat(devnat,temps,natAvg);

    double maxDev[m];
    getMaxDev(maxDev,devnat);

    print(natAvg, average, maxDev);

    return 0;

}

void ReadData(double temps[m][n]) {
    /*Read all Temperatures*/
	for (int i=0; i<m; i++)
		for (int j=0; j<n; j++) {
            printf("Temp of City %d During %d 8-hour period: ",i,j);
            temps[i][j] = GetReal();
        }
}

double getNatAvg (double temps[m][n]) {
    /*Calculating The Average of all Cities&Temps*/
    double natavg = 0;
    for (int i=0; i<m; i++)
      for (int j=0; j<n; j+=1)
         natavg += temps[i][j];
    return natavg = natavg/(m*n);
}

void getCityAvg (double average[m], double temps[m][n]) {
    /*Calculating Average temp on each City*/
	for (int i=0; i<m; i++) {
        average[i] = 0;
        for (int j=0; j<n; j++) {
            average[i] += temps[i][j];
        }
        average[i] = average[i]/n;
    }
}

void getDevNat (double devnat[m][n], double temps[m][n], double natAvg) {
	/*Calculating Standard Deviation*/
    for (int i=0; i<m; i++)
        for (int j=0; j<n; j++)
            devnat[i][j] = fabs(natAvg-temps[i][j]);

}

void getMaxDev (double maxDev[m], double devnat[m][n]) {
	/*Calculating max Deviation*/
    for (int i=0; i<m; i++) {
        maxDev[i] = devnat[i][0];
        for(int j=1; j<n; j++)
            if (maxDev[i]<devnat[i][j]) maxDev[i] = devnat[i][j];
    }
}

void print (double natAvg, double average[m], double maxDev[m]) {
    /*Printing results*/
    printf("%3.1f\n", natAvg);
    for (int i=0; i<m; i+=1)
		printf("City %d  %.1f  %.1f\n",i, average[i], maxDev[i]);
    system("PAUSE");
}
