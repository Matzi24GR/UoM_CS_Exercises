#include <stdio.h>
#include "simpio.h"
#include <string.h>

void removeSpaces(char string[],char output[]);

int main(){
    char email[80];
    gets(email);
    char dst[80];

    removeSpaces(email,dst);

    int i;  for (i=0; dst[i]!='@';i++) printf("%c",dst[i]);
    printf("\n%d\n",i);
    int j;  for (j=i+1; dst[j]!='\0';j++) printf("%c",dst[j]);

    return 0;

}

void removeSpaces(char string[],char output[]) {
    int i;  for (i=0;   string[i]==' ';   i++);
    int j;  for (j=strlen(string)-1; string[j]== ' ';   j--);
    strncpy(output,string+i,j-i+1);
    output[j-i+1]='\0';
}
