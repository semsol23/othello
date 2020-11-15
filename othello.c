
#include "othello.h"
#include "util.h"

void printOthello(int gameboard[N][N]);
void initOthello(int gameboard[N][N]);
void printDashLine();

int isGameEnd(int gameboard[N][N]);


void printOthello(int gameboard[N][N]) {
    int oNum = 0;
    int xNum = 0;
    printf("  ");
    for(int i=0; i<N; i++){
        printf("%d ",i);
    }
    for(int i=0; i<N; i++){
        printDashLine(N);
        printf("\n%d|",i);
        for(int j=0; j<N; j++){
            if(gameboard[i][j] == 0){
                printf(" |");
            }else if(gameboard[i][j] == 1){
                printf("O|");
                oNum++;
            }else if(gameboard[i][j] == 2){
                printf("X|");
                xNum++;
            }
            
        }
    }
    printDashLine(N);
    printf("\n\n STATUS - WHITE : %d, BLACK : %d\n",oNum,xNum);
}

void initOthello(int gameboard[N][N]) {
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++ ){
            if((i==2 && j==2) || (i==3 && j==3)){
                gameboard[i][j] = 1;
            }else if((i==2 && j==3) || (i==3 && j==2)){
                gameboard[i][j] = 2;
            }else{
                gameboard[i][j] = 0;
            }
        }
    }
}

void printDashLine() {
    printf("\n -");
    for(int i=0; i<N; i++){
        printf("--");
    }
}

int isGameEnd(int gameboard[N][N]) {
    int whiteNum = 0;
    int blackNum = 0;
    int blankNum = 0;
    
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(gameboard[i][j] == 1) whiteNum++;
            else if(gameboard[i][j] == 2) blackNum++;
            else if(gameboard[i][j] == 0) blankNum++;
        }
    }
    // 1. There is just one color.
    if(whiteNum == 0 || blackNum == 0){
        printf("\n [END] There is just [%s] color.\n", whiteNum == 0 ? "black" : "white");
        return 1;
    }
    
    // 2. There is no blank.
    if(blankNum == 0){
        printf("\n [END] There is no blank\n");
        return 1;
    }
    return 0;
}