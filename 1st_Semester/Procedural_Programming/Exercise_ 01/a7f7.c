#include <stdio.h>

int getPoints(char word[21]);

int main() {

    printf("Enter Word: ");
    char word[21];
    fgets(word,sizeof(word),stdin);
    int points = getPoints(word);
    printf("%d points",points);

    return 0;
}

int getPoints(char word[21]) {
    int points = 0;
    int i;
    for (i=0;i<20;i++) {
        switch (word[i]) {
            case 'A':
            case 'E':
            case 'I':
            case 'L':
            case 'N':
            case 'O':
            case 'R':
            case 'S':
            case 'T':
            case 'U':
                points += 1;
                break;
            case 'D':
            case 'G':
                points += 2;
                break;
            case 'B':
            case 'C':
            case 'M':
            case 'P':
                points += 3;
                break;
            case 'F':
            case 'H':
            case 'V':
            case 'W':
            case 'Y':
                points += 4;
                break;
            case 'K':
                points += 5;
                break;
            case 'J':
            case 'X':
                points += 8;
                break;
            case 'Q':
            case 'Z':
                points += 10;
                break;
            default:
                points = points;
                break;
        }
    }
    return points;
}
