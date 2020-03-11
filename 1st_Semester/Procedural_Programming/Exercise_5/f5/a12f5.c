#include <stdio.h>
#include "simpio.h"

int main() {

    printf("Dwse ton arithmo twn mathitwn: ");
    int students = GetInteger(); //max 30
    printf("Dwse ton arithmo twn thematwn: ");
    int subjects = GetInteger(); //max 10

    double grades100[30][10];
    for (int i=0;i<students;i++) {
        for (int j=0;j<subjects;j++) {
            printf("Dwse th bathmologia tou %dou thematos tou %dou mathiti: ",j+1,i+1);
            grades100[i][j] = GetReal();
        }
    }

    double average[30];
    for (int i=0;i<students;i++) {
        average[i]=0;
        for (int j=0;j<subjects;j++) {
            average[i]+=grades100[i][j];
        }
        average[i]=average[i]/subjects;
    }

    for (int i=0;i<students;i++) {
        for (int j=0;j<subjects;j++) {
            printf("%6.1lf ", grades100[i][j]);
        }
        printf("%6.1lf\n",average[i]);

        for (int j=0;j<subjects;j++) {
            printf("%6.1lf ", grades100[i][j]/5.0);
        }
        printf("%6.1lf\n",average[i]/5.0);
    }


    return 0;
}
