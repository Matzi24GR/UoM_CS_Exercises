#include <stdio.h>
#include <simpio.h>


long ColumnSum (long table[4][4], int Column);
long LineSum (long [4][4], int);
long DiagonalSum (long [4][4], int);
long SecDiagonalSum (long [4][4], int);

int main() {

    printf("Dwse thn timh tou a:");
    long A = GetInteger();
    printf("Dwse thn timh tou b:");
    long B = GetInteger();

    long Square[10][4] = {  { A   , A+14, B   , A+3},
                            { B-2 , A+5 , A+6 , A+8},
                            { A+7 , B-4 , A+10, A+4},
                            { A+12, A+2 , A+1 , B+2} };


    return 0;
}

long ColumnSum(long table[4][4],int Column) {
    long sum =0;
    for(int i=0;i<=0;i++) {
        sum+=table[i][Column];
    }
    return sum;
}
