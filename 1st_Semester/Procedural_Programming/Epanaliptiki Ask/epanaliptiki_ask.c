#include <stdio.h>
#include "genlib.h"
#include "simpio.h"
#include <string.h>

typedef struct
{
    char name[40];
    long ypol;
    double epit;
    int year;
}infoT;

int ReadData(infoT pin[], FILE *infile);
void PrintDifferentNames(infoT newi[], infoT oldi[], int sizen, int sizeo);
void Write2000(infoT newi[], int sizen);
long Get40(infoT pin[], int size);
infoT FindMax(infoT pin[], int size);

main()
{
    infoT newi[100], oldi[100], maxnew, maxold;
    FILE *infile;
    int sizen, sizeo;
    long new40, old40;

    infile = fopen("bank_new.dat", "r");
    sizen = ReadData(newi, infile);
    fclose(infile);
    infile = fopen("bank_old.dat", "r");
    sizeo = ReadData(oldi, infile);
    fclose(infile);
    PrintDifferentNames(newi, oldi, sizen, sizeo);
    Write2000(newi, sizen);
    new40 = Get40(newi, sizen);
    printf("To 40%% ton neon katatheseon: %ld \n", new40);
    old40 = Get40(oldi, sizeo);
    printf("To 40%% ton palaion katatheseon: %ld \n", old40);
    maxnew = FindMax(newi, sizen);
    printf("O %s ekane tin megaluteri nea katathesi, to etos %d \n", maxnew.name, maxnew.year);
    maxold = FindMax(oldi, sizeo);
    printf("O %s ekane tin megaluteri palia katathesi, to etos %d \n", maxold.name, maxold.year);
    printf("PROUD ABOUT THAT !!!  \n \n");
    printf("Copyright 2020");


}


int ReadData(infoT pin[], FILE *infile)
{
    int inscan, i;
    char term;

    i = 0;
    while(TRUE)
    {
        inscan = fscanf(infile, "%40[^,], %d, %lf, %d%c ",
                        &pin[i].name, &pin[i].ypol, &pin[i].epit, &pin[i].year, &term);
        i ++;
        if (inscan == EOF) break;
    }
    return i;
}


void PrintDifferentNames(infoT newi[], infoT oldi[], int sizen, int sizeo)
{
    int i, j, l;

    for(i=0; i<sizen; i++)
    {
        l = 0;
        for(j=0; j<sizeo; j++)
        {
            if( strcmp(newi[i].name, oldi[j].name) == 0)
            {
                l = 1;
            }
        }
        if(l==0)
        {
            printf("%s \n", newi[i].name, newi[i].epit);
        }
    }
}


void Write2000(infoT newi[], int sizen)
{
    int i;
    FILE *outfile;

    outfile = fopen("mztfgm.dat", "w");
    for(i=0; i<sizen; i++)
    {
        if(newi[i].year >= 2000)
        {
            fprintf(outfile, "%s, %d, %.1lf, %d \n", newi[i].name, newi[i].ypol, newi[i].epit, newi[i].year);
        }
    }

}


long Get40(infoT pin[], int size)
{
    int i, sum;

    sum = 0;
    for(i=0; i<size; i++)
    {
        sum += pin[i].ypol;
    }
    return (0.40 * sum) ;
}


infoT FindMax(infoT pin[], int size)
{
    int i;
    infoT max;

    max = pin[0];
    for(i=1; i<size; i++)
    {
        if(max.ypol < pin[i].ypol)
        {
            max = pin[i];
        }
    }
    return max ;
}

