#include <stdio.h>
#include <string.h>
#include "simpio.h"

void printCommon(char word1[30],char word2[30]);

int main() {

    printf("Please insert two word to find the common characters.");
    char word1[30],word2[30];
    printf("\nWord 1: ");
    gets(word1);
    printf("Word 2: ");
    gets(word2);

    printCommon(word1,word2);

    return 0;
}

void printCommon(char word1[30],char word2[30]) {
    printf("Common Characters of %s in %s: ",word1,word2);
    char common[30];
    int commonI=0;
    for (int i=0;i<29;i++) {
        bool found = FALSE;
        for (int j=0;j<29;j++){
            if(word1[i]==word2[j])
                found = TRUE;
        }
        if (found) {
            common[commonI]=word1[i];
            commonI++;
        }
    }
    common[commonI] = '\0';
    printf("%s",common);
    printf("\n----");
    printf("\nSet of (unique) Common Characters of %s and %s: ",word1,word2);
    for (int i=0;i<commonI;i++) {
        bool found = FALSE;
        for (int j=0;j<i;j++){
            if(common[i]==common[j])
                found = TRUE;
        }
        if (!found) printf("%c",common[i]);
    }
    printf("\n----");
}
