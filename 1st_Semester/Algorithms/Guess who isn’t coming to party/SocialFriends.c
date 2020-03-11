#include <stdio.h>
#include <string.h>

void readInput(int N ,char names[N][30],int input, int relationships[N][N]);
int calculateFriends(int N,char names[N][30],char namesNotComing[N][30], int relationships[N][N]);

int main() {

    printf("Number of friends (0 to load the example) : ");
    int input;  scanf("%d",&input);
    int N;      if (input!=0) N=input; else N=9;

    int relationships[N][N]; char names[N][30]; char namesNotComing[N][30];
    readInput(N,names, input, relationships);

    int maxFriends = calculateFriends(N,names,namesNotComing,relationships);

    printf("\n\nThe max possible number of friends coming to the party is %d\nand those not coming are:\n",maxFriends);
    for (int i=0;i<N-maxFriends;i++) printf("%25s %s\n","|",namesNotComing[i]);

    return 0;
}

void readInput(int N ,char names[N][30], int input, int relationships[N][N]) {
    if (input!=0) {
        printf("Enter Names of friends: \n");
        for (int i=0;i<N;i++) {
            printf("%d: ",i+1);
            scanf("%s",names[i]);
            for(int j=0;j<N;j++) relationships[i][j] =0;
        }
        for (int i=0;i<N;i++) {
            printf("Enter code of friends %s dislikes (one per line, 0 for end)\n",names[i]);
            int input=100;
            while (input != 0) {
                printf("Code: ");
                scanf("%d",&input);
                if (input!=0) {
                    relationships[i][input-1]=1;
                    printf("(%s)\n",names[input-1]);
                }
            }
        }
    } else {
                                                                  //            nikos  eua	petros	giannis	  manos	 lydia	 apostolos	 maria	dimitris
        int relationshipsEx[9][9] = { {0,0,0,0,0,0,0,0,0},        //nikos       0	     0	  0	       0	   0	   0	   0	       0	   0
                                      {0,0,0,0,1,0,0,0,0},        //eua                  .
                                      {0,0,0,0,0,1,0,0,0},        //petros               .
                                      {0,0,0,0,0,0,1,0,0},        //giannis              .
                                      {0,1,0,0,0,1,1,0,0},        //manos
                                      {0,0,1,0,1,0,0,1,1},        //lydia       0	     0	  1 	   0	    1	   0	   0	        1	    1
                                      {0,0,0,1,1,0,0,0,0},        //apostolos            .
                                      {0,0,0,0,0,1,0,0,1},        //maria                .
                                      {0,0,0,0,0,1,0,1,0},    };  //dimitris             .

        char namesEx[9][30] = {"nikos" , "eua", "petros", "giannis", "manos", "lydia", "apostolos", "maria", "dimitris"};

        for (int i=0;i<N;i++) for (int j=0;j<N;j++) relationships[i][j] = relationshipsEx[i][j];
        for (int i=0;i<N;i++) strcpy(names[i],namesEx[i]);
    }
}

int calculateFriends(int N,char names[N][30],char namesNotComing[N][30], int relationships[N][N]){
    int friendsComing = N;
    int remainingDislikedFriends[N];
    for (int i=0;i<N;i++) remainingDislikedFriends[i]=0;
    for (int i=0;i<N;i++) {
        for (int j=0;j<N;j++) {
            remainingDislikedFriends[i] += relationships[i][j];
        }
    }
    for (int lines=N;lines>0;lines--) {
        for(int i=0;i<N;i++) {
            if (remainingDislikedFriends[i] == lines) {
                strcpy(namesNotComing[N-friendsComing],names[i]);
                friendsComing--;
                remainingDislikedFriends[i]=0;
                for (int k=0;k<N;k++) if (relationships[k][i]==1) remainingDislikedFriends[k]--;
            }
        }
    }
    return friendsComing;
}