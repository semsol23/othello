
#include "othello.h"
#include "util.h"

/*변수 및 함수 정의*/

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
    printf("  "); /*열 숫자 시작 전 spacebar*/
    for(i=0; i<N; i++){ 
        printf("%d ",i); /*0~5 띄어쓰기 포함해서 나열*/
    }
    for(i=0; i<N; i++){
        printDashLine(N); /*줄바꿈 후 첫번째 dashline*/
        printf("\n%d|",i); /*줄바꿈 사용해서 행 숫자 세로로 나열*/
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
            if((i==2 && j==2) || (i==3 && j==3)){ /*행과 열이 모두 2 또는 모두 3일 때 */
                gameboard[i][j] = 1; /*O 표기*/
            }else if((i==2 && j==3) || (i==3 && j==2)){ /*행과 열이 2,3 이거나 3,2 일 때*/
                gameboard[i][j] = 2; /*X 표기*/
            }else{ /*위 두 가지 상황이 아닐 때*/
                gameboard[i][j] = 0; /*| 표기*/
            }
        }
    }
}

void printDashLine() {
    int i;
    printf("\n -");
    for(i=0; i<N; i++){
        printf("--"); /*- 2개씩 행과 열 수(N)만큼 */
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
    if(userInput[0] >= N || userInput[1] >= N){ /*행 또는 열 값이 행과 열 수 보다 크거나 같을 때 */
        printf("[INVALID INPUT!] Should be less than %d.\n", N); /*이 때 출력되는 invalid*/
        return 0;
    }else if(gameboard[userInput[0]][userInput[1]] != 0){ /*이미 O 또는 X로 차지된 칸을 선택할 때*/
        printf("[INVALID INPUT!] Already occupied.\n"); /*이 때 출력되는 invalid*/
        return 0;
    }else if(canFlip(color, userInput, gameboard) == 0){ /*뒤집을 반대색이 하나도 없는 자리일 때*/
        printf("[INVALID INPUT!] No flip happens.\n"); /*이 때 출력되는 invalid*/
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
    int toCheckPointsValue[8][2] = { /*선택한 자리를 기준으로 인접한 8가지 방향에 대한 좌표 설정*/
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
    int whiteNum = 0; /*초기값 설정*/
    int blackNum = 0; /*초기값 설정*/
    int blankNum = 0; /*초기값 설정*/
    
    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            if(gameboard[i][j] == 1) whiteNum++; /*게임판 배열에서 1(O)가 출력될 때 마다 whiteNum 변수에 +1*/
            else if(gameboard[i][j] == 2) blackNum++; /*게임판 배열에서 2(X)가 출력될 때 마다 blackNum 변수에 +1*/
            else if(gameboard[i][j] == 0) blankNum++; /*게임판 배열에서 0( )가 출력될 때 마다 blankNum 변수에 +1*/
        }
    }
    if(whiteNum == 0 || blackNum == 0){ /*O 또는 X가 0개 일 때*/
        printf("\n [END] There is just [%s] color.\n", whiteNum == 0 ? "black" : "white"); /*O가 0개이면 black만 있음을 출력*/
        return 1;
    }
    if(blankNum == 0){ /*blank가 0개 일 때*/
        printf("\n [END] There is no blank\n"); /*더 이상 놓을 수 있는 빈칸이 없음을 출력*/
        return 1;
    }
    return 0;
}

void checkResult(int gameboard[N][N]) {
    int i, j;
    int whiteNum = 0; /*초기값 설정*/
    int blackNum = 0; /*초기값 설정*/
    
    for(i=0; i<N; i++) {
        for(j=0; j<N; j++) {
            if(gameboard[i][j] == 1) whiteNum++; /*게임판 배열에서 1(O)가 출력될 때 마다 whiteNum 변수에 +1*/
            else if(gameboard[i][j] == 2) blackNum++;/*게임판 배열에서 2(X)가 출력될 때 마다 blackNum에 +1*/
        }
    }
    if(whiteNum == blackNum){ /*O와 X의 갯수가 같은 경우*/
        printf("[ DRAW ]\n- - - GAME END - - -\n");
    }else{ /*O와 X의 갯수가 다른 경우*/
        printf("[ %s ] is WIN!\n- - - GAME END - - -\n",whiteNum > blackNum ? "WHITE" : "BLACK"); /*승자 출력, whiteNum이 blackNum보다 큰 경우 승자는 white, 반대면 black*/
    }
}
