#include <stdio.h>


int main() {
    FILE *file = fopen("i5f9.dat","r");
    int words = 0;
    int lines = 0;
    int chars = 0;
    char last = 'a';
    while (1) {
        char c = fgetc(file);

        if (c == '\n') lines++;

        if (last != ' ' && c == ' ') words++;
        last = c;

        if (c == EOF) break;
        else chars++;
    }
    printf("Lines: %d\nWords: %d\nChars: %d",lines,words,chars);
    fclose(file);
    return 0;
}

