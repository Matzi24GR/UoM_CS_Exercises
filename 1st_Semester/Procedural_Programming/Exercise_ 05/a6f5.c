#include <stdio.h>
#include <simpio.h>

long ColumnSum(long table[4][4],int);
long LineSum(long table[4][4],int);
long DiagonalSum(long table[4][4]);
long SecDiagonalSum(long table[4][4]);

int main() {
    printf("Dwse thn timh tou a:");
    long A = GetInteger();
    printf("Dwse thn timh tou b:");
    long B = GetInteger();

    long Square[4][4] = {  { A   , A+14, B   , A+3},
                            { B-2 , A+5 , A+6 , A+8},
                            { A+7 , B-4 , A+10, A+4},
                            { A+12, A+2 , A+1 , B+2} };



    long SumsCol[4];
    long SumsLine[4];
    long SumsDiag[2];

    for (int i=0;i<4;i++) {
        SumsCol[i]= ColumnSum(Square,i);
        SumsLine[i]=LineSum(Square,i);
    }
    SumsDiag[0]=DiagonalSum(Square);
    SumsDiag[1]=SecDiagonalSum(Square);


    for (int i=0;i<4;i++) {
        for (int j=0;j<4;j++) {
        printf("%2ld ",Square[i][j]);
        }
        printf("| %ld\n",SumsLine[i]);
    }
    printf("------------\n");
    for (int i=0;i<4;i++) printf("%ld ",SumsCol[i]);
    printf("\n%ld, ", SumsDiag[0]);
    printf("%ld\n",SumsDiag[1]);


    int isMagic = TRUE;
    for (int i=0;i<4;i++) if (SumsCol[0]!=SumsCol[i] || SumsCol[0]!=SumsLine[i]) isMagic = FALSE;
    for (int i=0;i<2;i++) if (SumsCol[0]!=SumsDiag[i]) isMagic = FALSE;

    if (isMagic) printf("MAGIC"); else printf("NOT MAGIC");

    return 0;
}

long ColumnSum(long table[4][4],int Column) {
    long sum =0;
    for(int i=0;i<4;i++) {
        sum+=table[i][Column];
    }
    return sum;
}

long LineSum(long table[4][4],int Line) {
    long sum =0;
    for(int i=0;i<4;i++) {
        sum+=table[Line][i];
    }
    return sum;
}

long DiagonalSum(long table[4][4]) {
    long sum=0;
    for(int i=0;i<4;i++) {
        sum+=table[i][i];
    }
    return sum;
}

long SecDiagonalSum(long table[4][4]) {
    long sum=0;
    for(int i=0;i<4;i++) {
        sum+=table[i][3-i];
    }
    return sum;
}

