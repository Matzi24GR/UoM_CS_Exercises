#include <stdio.h>

typedef struct {
    int code;
    char name[29];
    int points;
} playerT;

int readFromFile(FILE *file, playerT players[]);
void writeToFile(FILE *file, playerT players[],int N);

int main() {
    FILE *input = fopen("i11f9.dat","r");
    playerT players[100];
    int playerCount = readFromFile(input,players);

    FILE *output = fopen("baso11f9.dat","w");
    writeToFile(output,players,playerCount);

    return 0;
}

int readFromFile(FILE *file, playerT players[]) {
    int i=0;
    while (1) {
        int nscan = fscanf(file,"%d,%28[^,],%d",&players[i].code,&players[i].name,&players[i].points);
        if (nscan == EOF) break;
        else i++;
    }
    return i;
}

void writeToFile(FILE *file, playerT players[],int N) {
    int over10 = 0;
    int sum =0;

    fprintf(file,"%-28s %-6s\n","ONOMATEPWNYMO","PONTOI");
    fprintf(file,"-----------------------------------\n");

    for (int i=0; i<N; i++) {
        fprintf(file,"%-28s %-6d\n",players[i].name,players[i].points);

        sum+= players[i].points;
        if (players[i].points>=10) over10++;
    }

    fprintf(file,"-----------------------------------\n");
    fprintf(file,"%-28s %-6d\n","SYNOLO PONTWN",sum);
    fprintf(file,"%-28s %-6d\n","SYNOLO PAIKTVN >= 10",over10);

}
