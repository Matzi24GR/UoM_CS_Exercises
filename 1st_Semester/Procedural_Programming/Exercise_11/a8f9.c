#include <stdio.h>

int main() {
    FILE *input = fopen("i8f9.dat","r");
    FILE *output = fopen("o8f9.dat","w");

    int nscan;
    long code;
    double salary;
    char termch;
    while (nscan = fscanf(input,"%d %lf%c",&code,&salary,&termch) != EOF)
        fprintf(output, "%7d%13.1lf\n", code, salary*1.2);

    return 0;
}
