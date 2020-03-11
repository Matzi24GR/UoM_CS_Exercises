#include <stdio.h>
#include "simpio.h"
#define students 10
#define lessons 3

void readData(int array[][lessons]);
int getFails(int array[][lessons]);
int getBest(int array[][lessons]);
double getAvg(int array[][lessons],int student);

int main() {

    int array[20][3];
    readData(array);

    int fails = getFails(array);
    int best = getBest(array);
    printf("Plithos apotyxonton: %d  %.2f%%",fails, fails*100/students*1.0);
    printf("\nPlithos aristoyxon: %d  %.2f%%",best, best*100/students*1.0);

    return 0;
}

void readData(int array[][lessons]){
    for (int i=0; i<students; i++){
        printf("Mathitis %d",i+1);
        printf("\n--------------\n");
        for (int j=0; j<lessons; j++){
            printf("Mathima %d:",j+1);
            array[i][j] = GetInteger();
        }
    }
}

double getAvg(int array[][lessons],int student) {
    int sum = 0;
    for (int i=0; i<lessons; i++){
        sum = sum + array[student][i];
    }
    return sum/lessons;

}

int getFails(int array[][lessons]) {
    int count = 0;
    for (int i=0; i<students; i++) {
        if(getAvg(array,i)<9.5) count++;
    }
    return count;
}

int getBest(int array[][lessons]) {
    int count = 0;
    for (int i=0; i<students; i++) {
        if(getAvg(array,i)>=18.5) count++;
    }
    return count;
}
