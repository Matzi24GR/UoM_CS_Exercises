#include <stdio.h>
#define celebrities 21
#define H 25
//const char *names[21] = {"Accept","Antrax","Black Sabbath","Helloween","Iron Maiden","Judas Priest","Manowar","Megadeth","Metallica","Mötley Crüe","Nazareth","Ozzy","Pantera","Queensrÿche","Rammstein","Raven","Saxon","Scopions","Sepultura","Slayer","W.A.S.P."};

void getCelebSchedule(int schedule[][H]);
void getCelebsPerHour(int schedule[][H], int celebs[]);
int  getMaxCelebs(int celebs[]);

int main() {

    int schedule[celebrities][H];
    getCelebSchedule(schedule);

    //for(int i=0;i<celebrities; i++) {printf("\n%s\n",names[i]);for (int j = 17; j <H ; j++) printf("%d:%d  ",j,schedule[i][j]);}

    int celebs[H];
    getCelebsPerHour(schedule,celebs);
    //for (int hour=0;hour<H;hour++) printf("%d: %d\n",hour,celebs[hour]);

    int BestTime = getMaxCelebs(celebs);
    printf("The best time to party is at %d",BestTime);
    
    return 0;
}

void getCelebSchedule(int schedule[][H]) {
    int input[celebrities][2] = {    {20,23},
                                     {22,24},
                                     {19,20},
                                     {19,21},
                                     {19,20},
                                     {21,23},
                                     {20,22},
                                     {20,21},
                                     {19,21},
                                     {20,22},
                                     {22,23},
                                     {18,21},
                                     {18,22},
                                     {23,24},
                                     {22,24},
                                     {19,24},
                                     {20,23},
                                     {22,24},
                                     {19,23},
                                     {18,20},
                                     {20,21},   };

    for (int i=0;i<celebrities; i++) {
        for (int hour=0; hour < 25; hour++ ) {
            if (hour>=input[i][0] && hour<input[i][1])
                schedule[i][hour] = 1;
            else
                schedule[i][hour] = 0;
        }
    }


}

void getCelebsPerHour(int schedule[][25], int celebs[]) {
    for (int hour=0;hour<H;hour++){
        celebs[hour]=0;
        for (int i=0;i<celebrities;i++) {
            celebs[hour]+=schedule[i][hour];
        }
    }
}

int  getMaxCelebs(int celebs[]) {
    int max=0;
    for (int hour=0;hour<H;hour++){
        if (celebs[hour]>celebs[max]) max=hour;
    }
    return max;
}