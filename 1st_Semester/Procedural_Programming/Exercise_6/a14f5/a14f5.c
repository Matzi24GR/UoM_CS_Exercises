#include <stdio.h>
#include <simpio.h>

void fillArray(int size, long array[]);
void printArray(int size, long array[]);
int FindMaxsPos(int size, long array[], int index[]);

int main() {

    long array[50];
    printf("Dwse to plhthos twn stoixeiwn: ");
    int M = GetInteger();
    fillArray(M,array);
    printArray(M,array);
    int index[50];
    long maxCount = FindMaxsPos(M,array,index);
    printf("\nmaximum %ld",array[index[0]]);
    printf("\nPlithos maximum %d", maxCount);
    printf("\nPositions of maximum ");
    printArray(maxCount,index);
    return 0;
}

void fillArray(int size, long array[]) {
    for (int i=0; i<size; i++) {
        array[i] = GetLong();
    }
}

void printArray(int size, long array[]) {
    for (int i=0; i<size; i++) {
        printf("%ld ",array[i]);
    }
}

int FindMaxsPos(int size, long array[], int index[]) {
    int count = -1;
    long max = array[0];
    for (int i=0; i<size; i++) {
        if(array[i]==max) {
            count++;
            index[count]=i;
        } else if (array[i]>max) {
            count = 0;
            max = array[i];
            index[count] = i;
        }
    }
    return count+1;
}
