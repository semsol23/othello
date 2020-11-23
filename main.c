#include <stdio.h>
#include <stdlib.h>

#include "util.h"
#include "othello.h"

int gameboard[N][N];

int main(int argc, char *argv[]) {

    int userInput[2], flipResult[8];
    int flipNum = 0, passCnt=0; /*초기값 설정*/
    char turnColor[6] = "white"; /*첫번째 player는 흰돌*/
    int temp;

    initOthello(gameboard); /*게임판 초기화*/
    
    while(isGameEnd(gameboard) == 0){ /*아직 게임이 종료되지 않았을 때*/
        
        printOthello(gameboard); /*게임판 출력*/
        if(isCanNotPlay(turnColor, gameboard) == 1){/*돌을 배치할 수 없을 때*/
            printf("[%s] can not place. Turn Change.\n",turnColor);/*차례인 돌을 놓을 곳이 없어 반대색으로 차례 넘긴다고 출력*/
            changeColor(turnColor);/*반대색 문자열로 변경*/
            passCnt++;/*pass 횟수 +1*/
            continue;
        }else{ /*돌을 배치할 수 있을 때*/
            passCnt = 0;
        }
        if(passCnt > 1){ /*pass 횟수가 2이상일 때*/
            printf("White player and Black player can not play anymore.\n");/*두 플레이어가 모두 더이상 뒤집을 수 없을 때 더 이상 게임할 수 없음을 출력*/
            break;
        }

        printf("\nput a new %s othello : ", turnColor);/*다음 차례의 플레이어 선언*/
        scanf("%d %d", &userInput[0], &userInput[1]);/*1 3 의 형태로 입력한 좌표를 게임판 좌표로서 userInput에 대입*/
        
        if(validateUserInput(turnColor, userInput, gameboard) == 1){ /*유요한 좌표일 때*/
			initFlipResult(flipResult);/*결과 출력 배열, flipResult 초기화*/
            flipNum = doFlip(turnColor, userInput, flipResult, gameboard);/*뒤집을 돌 갯수*/
            while(canFlip(turnColor, userInput, gameboard) == 1){
                flipNum += doFlip(turnColor, userInput, flipResult, gameboard);
            }
            if(flipNum > 0){
				printFlipResult(turnColor, flipResult);/*뒤집은 돌 결과 출력*/
                changeColor(turnColor);/*반대색 문자열로 변경*/
            }
        }
		
    }
    printOthello(gameboard);/*게임판 현황 출력*/
    
    printf("If you exit the program, enter any key.\n");
    scanf("%d", &temp);
    return 0;
}
