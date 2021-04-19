#include <stdio.h>
#include "simpio.h"
#define months 3
#define cities 5


double getAverageMonth(double array[cities][months],int month);
double getAverageCity(double array[cities][months],int city);

int main() {
    double revenueArray[cities][months];
    for (int i=0;i<cities;i++) for (int j=0;j<months;j++) revenueArray[i][j] = GetReal();
    //for (int i=0;i<cities;i++) {for (int j=0;j<months;j++) printf("%f ",revenueArray[i][j]);printf("\n");}

    for (int i=0;i<cities;i++) printf("%lf  ",getAverageCity(revenueArray,i));
    printf("\n");

    for (int j=0;j<months;j++) printf("%lf  ",getAverageMonth(revenueArray,j));
    printf("\n");

    int min = revenueArray[0][0]+999;
    int City,Month;
    for (int i=0;i<cities;i++)
        for (int j=0;j<months;j++)
            if (revenueArray[i][j]<min) {
                min=revenueArray[i][j];
                City=i;
                Month=j;
            }
    printf("%lf sthn %dh polh, ton %do mhna",revenueArray[City][Month],City+1,Month+1);
    return 0;
}

double getAverageMonth(double array[cities][months],int month){
    double count =0;
    for (int i=0;i<cities;i++) count+=array[i][month];
    return count/cities*1.0;
}

double getAverageCity(double array[cities][months],int city){
    double count =0;
    for (int j=0;j<months;j++) count+=array[city][j];
    return count/months*1.0;
}

