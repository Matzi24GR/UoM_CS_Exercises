#include <stdio.h>
#include <string.h>

#define BandLimit 100
#define strSize 20

int getBandSchedule(char names[BandLimit][strSize], int schedule[BandLimit][2]);   //epistrefei ton arithmo twn sygkrotimatwn
void getBestTime(int schedule[BandLimit][2], char names[BandLimit][strSize], int limit, char SolutionBandsArray[BandLimit][strSize][BandLimit], int *SolutionBandsCount, int *Solutions, int SolutionHours[BandLimit]);

int main() {
    //eisagogh dedomenwn
    char names[BandLimit][strSize];  int schedule[BandLimit][2];
    int bands = getBandSchedule(names,schedule);

    //emfanisi dedomenwn
    for(int i=0;i<bands; i++) {printf("%20s   ",names[i]);printf("%d-%d \n",schedule[i][0],schedule[i][1]);}



    //algorithmos
    char SolutionBandsArray[BandLimit][strSize][BandLimit];
    int SolutionHours[BandLimit];
    int SolutionBandsCount=0;
    int Solutions;
    getBestTime(schedule, names, bands, SolutionBandsArray, &SolutionBandsCount, &Solutions, SolutionHours);
    printf("\nThere is/are %d Best Hour(s) in any of which he will meet %d Band(s)", Solutions, SolutionBandsCount);
    printf("\nThe Best Hour(s) is/are :\n");
    for (int i=0; i <Solutions; i++) printf("               %2d-%-2d |",SolutionHours[i],SolutionHours[i]+1);
    printf("\n");
    for (int i=0; i <Solutions; i++) printf("---------------------|");
    for (int i=0; i < SolutionBandsCount; i++) {
        printf("\n");
        for (int j=0;j<Solutions; j++) printf("%20s |", SolutionBandsArray[i][j]);
    }

    return 0;
}

int getBandSchedule(char names[BandLimit][strSize], int schedule[BandLimit][2]){
    printf("Band count (0 to input example): ");
    int count;
    scanf("%d",&count);

    if (count<0 || count >100) {
        //elegxos timhs
        printf("\nValues from 0 to %d only\n", BandLimit);
        count=getBandSchedule(names,schedule);

    } else if (count == 0) {
        count = 21;
        //ta dedomena tou paradeigmatos
        strcpy(names[0],"Accept");
        strcpy(names[1],"Antrax");              //logika yparxei kaliteros tropos na ta kanw ola auta
        strcpy(names[2],"Black Sabbath");
        strcpy(names[3],"Helloween");
        strcpy(names[4],"Iron Maiden");
        strcpy(names[5],"Judas Priest");
        strcpy(names[6],"Manowar");
        strcpy(names[7],"Megadeth");
        strcpy(names[8],"Metallica");
        strcpy(names[9],"Mötley Crüe");
        strcpy(names[10],"Nazareth");
        strcpy(names[11],"Ozzy");
        strcpy(names[12],"Pantera");
        strcpy(names[13],"Queensrÿche");
        strcpy(names[14],"Rammstein");
        strcpy(names[15],"Raven");
        strcpy(names[16],"Saxon");
        strcpy(names[17],"Scorpions");
        strcpy(names[18],"Sepultura");
        strcpy(names[19],"Slayer");
        strcpy(names[20],"W.A.S.P");

        schedule[0][0] = 20; schedule[0][1] = 23;
        schedule[1][0] = 22; schedule[1][1] = 24;         //.....
        schedule[2][0] = 19; schedule[2][1] = 20;
        schedule[3][0] = 19; schedule[3][1] = 21;
        schedule[4][0] = 19; schedule[4][1] = 20;
        schedule[5][0] = 21; schedule[5][1] = 23;
        schedule[6][0] = 20; schedule[6][1] = 22;
        schedule[7][0] = 20; schedule[7][1] = 21;
        schedule[8][0] = 19; schedule[8][1] = 21;
        schedule[9][0] = 20; schedule[9][1] = 22;
        schedule[10][0] = 22; schedule[10][1] = 23;
        schedule[11][0] = 18; schedule[11][1] = 21;
        schedule[12][0] = 18; schedule[12][1] = 22;
        schedule[13][0] = 23; schedule[13][1] = 24;
        schedule[14][0] = 22; schedule[14][1] = 24;
        schedule[15][0] = 19; schedule[15][1] = 24;
        schedule[16][0] = 20; schedule[16][1] = 23;
        schedule[17][0] = 22; schedule[17][1] = 24;
        schedule[18][0] = 19; schedule[18][1] = 23;
        schedule[19][0] = 18; schedule[19][1] = 20;
        schedule[20][0] = 20; schedule[20][1] = 21;



    } else {
        for (int i=0; i<count; i++) {
            /*Sto mathima toy diadikastikou programtismou xrhsimopoioume
             thn bibliothiki tou stanford gia eisagogi dedomenwn
             opote isos na min einai toso swsto
             Alloi mporei na to exoun kanei me GetInteger ktl ths bibliothikis   */
            printf("Name of Band #%d: ",i+1);
            scanf("%s",names[i]);
            printf(" Arrival Time of Band: ");
            scanf("%d",&schedule[i][0]);
            printf(" Departure Time of Band: ");
            scanf("%d",(&schedule[i][1]));
            printf("-----------------------\n");
        }
    }
    return count;
}

void getBestTime(int schedule[BandLimit][2], char names[BandLimit][strSize], int limit, char SolutionBandsArray[BandLimit][strSize][BandLimit], int *SolutionBandsCount, int *Solutions, int SolutionHours[BandLimit]) {
    int max=-1;
    *Solutions = 0;
    for (int hour=0; hour<24; hour++){
        int count=0;
        for (int band=0; band<limit; band++){
            if (hour>=schedule[band][0] && hour<schedule[band][1]) count++;     //katametrisi ana ora
        }
        if (count>max) {
            *Solutions = 1;
            max = count;
            SolutionHours[0] = hour;
        } else if (count == max) {
            SolutionHours[*Solutions] = hour;
            (*Solutions)++;
        }
    }
    for (int i = 0; i<*Solutions; i++) {
        int SolutionBandsIndex=0;
        for (int band=0; band<limit; band++) {
            if (SolutionHours[i]>=schedule[band][0] && SolutionHours[i]+1<=schedule[band][1]) {
                strcpy(SolutionBandsArray[SolutionBandsIndex][i], names[band]);
                SolutionBandsIndex++;
            }
        }
    }
    *SolutionBandsCount = max;
}

