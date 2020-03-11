#include <stdio.h>

void getArray(int array[100],  int N);
void printArray(int array[100],int N);
int getCountOfLessOrEqualThan(int array[100], int N, int x);
int getCountOfGreaterOrEqualThan(int array[100], int N, int x);

int main()
{
    int array[100];
    //int array[100] = {187, 33, 159, 112, 2, 174, 14, 53, 3, 145, 28, 36, 50, 100, 171, 176, 148, 177, 175, 134};
    int N;
    scanf("%d",&N);
    getArray(array,N);


    int a, b;
    scanf("%d",&a);
    scanf("%d",&b);

    int countA = getCountOfLessOrEqualThan(array, N, a);
    int countB = getCountOfGreaterOrEqualThan(array, N, b);
    int countAB = N - countA - countB;

    printArray(array,N);
    printf("\n%d %d\n",a,b);
    printf("%d %d %d\n",countA, countB, countAB);
    return 0;
}

void getArray(int array[100], int N) {

    for (int i=0; i<N; i++) {
        scanf("%d",&array[i]);
    }
}

void printArray(int array[100],int N) {
    for (int i=0; i<N; i++) {
        printf("%d ", array[i]);
    }
}

int getCountOfLessOrEqualThan(int array[100], int N, int x) {
    int count = 0;
    for (int i=0; i<N; i++) if (array[i]<=x) count++;
    return count;
}

int getCountOfGreaterOrEqualThan(int array[100], int N, int x){
    int count = 0;
    for (int i=0; i<N; i++) if (array[i]>=x) count++;
    return count;
}
