
#include "othello.h"
#include "util.h"

void printOthello(int gameboard[N][N]);
void initOthello(int gameboard[N][N]);
void printDashLine();

int isCanNotPlay(char turnColor[], int gameboard[N][N]);
int validateUserInput(char color[], int userInput[], int gameboard[N][N]);
int canFlip(char color[], int userInput[], int gameboard[N][N]);
int getFlipDirection(char color[], int userInput[], int gameboard[N][N]);
int isInSidePoint(int point[]);
int doFlip(char color[], int userInput[], int gameboard[N][N]);
int isGameEnd(int gameboard[N][N]);
void checkResult(int gameboard[N][N]);


void printOthello(int gameboard[N][N]) {
    int i, j;
    int oNum = 0;
    int xNum = 0;
    printf("  ");
    for(i=0; i<N; i++){
        printf("%d ",i);
    }
    for(i=0; i<N; i++){
        printDashLine(N);
        printf("\n%d|",i);
        for(j=0; j<N; j++){
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
    int i, j;
    for(i=0; i<N; i++){
        for(j=0; j<N; j++ ){
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
    for i;
    printf("\n -");
    for(i=0; i<N; i++){
        printf("--");
    }
}


int isCanNotPlay(char turnColor[], int gameboard[N][N]){
    int i, j;
    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            if(gameboard[i][j] == 0){
                int blankPoint[2] = {i,j};
                if(canFlip(turnColor, blankPoint, gameboard)) return 0;
            }
        }
    }
    return 1;
}

int validateUserInput(char color[], int userInput[], int gameboard[N][N]) {
    // 1 : User input is over than N.
    if(userInput[0] >= N || userInput[1] >= N){
        printf("[INVALID INPUT!] Should be less than %d.\n", N);
        return 0;
    }else if(gameboard[userInput[0]][userInput[1]] != 0){
        printf("[INVALID INPUT!] Already occupied.\n");
        return 0;
    }else if(canFlip(color, userInput, gameboard) == 0){
        printf("[INVALID INPUT!] No flip happens.\n");
        return 0;
    }
    
    return 1;
}

int canFlip(char color[], int userInput[], int gameboard[N][N]) {
    if(getFlipDirection(color, userInput, gameboard) >= 0){
        return 1;
    }else{
        return 0;
    }
};

int getFlipDirection(char color[], int userInput[], int gameboard[N][N]) {
    int i;
    int colorInt = getColorToInt(color);
    int flipDirection = -1;
    int *checkPoint, *nextCheckPoint;
    int toCheckPointsValue[8][2] = {
        {-1,-1},
        {0,-1},
        {+1,-1},
        {+1,0},
        {+1,+1},
        {0,+1},
        {-1,+1},
        {-1,0}
    };
    
    for(i=0; i<8; i++){
        checkPoint = getCheckPoint(userInput, toCheckPointsValue[i]);
        if(isInSidePoint(checkPoint) == 1){
            if(gameboard[checkPoint[0]][checkPoint[1]] != 0
               && gameboard[checkPoint[0]][checkPoint[1]] != colorInt){ // 다른 색 찾았을때
                
                nextCheckPoint = getCheckPoint(checkPoint, toCheckPointsValue[i]);
                if(isInSidePoint(nextCheckPoint) == 0){
                    flipDirection = -1;
                    continue;
                }
                while(1){
                    if(gameboard[nextCheckPoint[0]][nextCheckPoint[1]] == colorInt){
                        flipDirection = i;
                        break;
                    }else if(gameboard[nextCheckPoint[0]][nextCheckPoint[1]] == 0){
                        flipDirection = -1;
                        break;
                    }else{
                        nextCheckPoint = getCheckPoint(nextCheckPoint, toCheckPointsValue[i]);
                        if(isInSidePoint(nextCheckPoint) == 0){
                            flipDirection = -1;
                            break;
                        }
                    }
                }
                if(flipDirection >= 0) break;
            }
        }
    }
    return flipDirection;
}

int isInSidePoint(int point[]) {
    if(point[0] < 0 || point[0] >= N || point[1] < 0 || point[1] >= N){
        return 0;
    }
    return 1;
};

int doFlip(char color[], int userInput[], int gameboard[N][N]) {
    int flipNum = 0;
    int colorInt = getColorToInt(color);
    int flipDirection = getFlipDirection(color, userInput, gameboard);
    int *nextPoint;
    int toCheckPointsValue[8][2] = {
        {-1,-1},
        {0,-1},
        {+1,-1},
        {+1,0},
        {+1,+1},
        {0,+1},
        {-1,+1},
        {-1,0}
    };
    gameboard[userInput[0]][userInput[1]] = colorInt;
    nextPoint = getCheckPoint(userInput, toCheckPointsValue[flipDirection]);
    while(1){
        
        if(gameboard[nextPoint[0]][nextPoint[1]] == colorInt){
            break;
        }else{
            gameboard[nextPoint[0]][nextPoint[1]] = colorInt;
            flipNum++;
        }
        nextPoint = getCheckPoint(nextPoint, toCheckPointsValue[flipDirection]);
    }
    
    return flipNum;
}

int isGameEnd(int gameboard[N][N]) {
    int i, j;
    int whiteNum = 0;
    int blackNum = 0;
    int blankNum = 0;
    
    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
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

void checkResult(int gameboard[N][N]) {
    int i, j;
    int whiteNum = 0;
    int blackNum = 0;
    
    for(i=0; i<N; i++) {
        for(j=0; j<N; j++) {
            if(gameboard[i][j] == 1) whiteNum++;
            else if(gameboard[i][j] == 2) blackNum++;
        }
    }
    if(whiteNum == blackNum){
        printf("[ DRAW ]\n- - - GAME END - - -\n");
    }else{
        printf("[ %s ] is WIN!\n- - - GAME END - - -\n",whiteNum > blackNum ? "WHITE" : "BLACK");
    }
}
