#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char name[31];
    int absentCount;
} StudentT;

void readInput(FILE *input,StudentT students[],int *absentStudents,int *Nstudents);
void writeOutput(FILE *output, int size, StudentT students[],int total);

int main() {

    FILE *input = fopen("i2f9.dat","r");
    FILE *output = fopen("o2f9.dat","w");
    if (input == NULL){
        printf("Cannot open input file i2f9.dat");
        exit(1);
    }
    StudentT students[100];
    int absentStudents=0;
    int Nstudents=0;
    readInput(input,students,&absentStudents,&Nstudents);
    writeOutput(output,absentStudents,students,Nstudents);
    fclose(input);
    fclose(output);
    return 0;
}

void readInput(FILE *input,StudentT students[],int *absentStudents,int *Nstudents) {
    int nscan,apousies;
    char name[31], comments[69],termch;
    int line = 0;
    while (1) {
        nscan = fscanf(input,"%30[^,],%d, %68[^\n]%c",name,&apousies,comments,&termch);
        if (nscan == EOF ) break;
        line++;
        if (nscan != 4 || termch != '\n') {
            printf("Error in line %d. Program termination\n",line);
            exit(1);
        }
        if (apousies > 100) {
            strcpy(students[*absentStudents].name,name);
            students[*absentStudents].absentCount = apousies;
            (*absentStudents)++;
        }
        (*Nstudents)++;
    }
}

void writeOutput(FILE *output, int size, StudentT students[],int total) {
    fprintf(output,"%-30s%-9s\n","ONOMATEPWNYMO","APOYSIES");
    for (int i=0; i<39; i++) fputc('-',output);
    fputc('\n',output);
    for (int i=0;i<size;i++) fprintf(output,"%-30s%9d\n", students[i].name, students[i].absentCount);
    for (int i=0;i<39;i++) fputc('-',output);
    fprintf(output,"\n");
    fprintf(output,"%-30s%9d\n","SYNOLO MATHITWN",total);
    fprintf(output,"%-30s%9d\n","SYNOLO APONTWN",size);
}
