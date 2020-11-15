#include <stdio.h>
#include <stdlib.h>

#include "util.h"
#include "othello.h"

int gameboard[N][N];

int main(int argc, char *argv[]) {

	int userInput[2];
    int flipNum = 0, passCnt=0;
    char turnColor[6] = "white";
    int temp;

	initOthello(gameboard);
    
    while(isGameEnd(gameboard) == 0){
        
        printOthello(gameboard);
        if(isCanNotPlay(turnColor, gameboard) == 1){
            printf("[%s] can not place. Turn Change.\n",turnColor);
            changeColor(turnColor);
            passCnt++;
            continue;
        }else{
            passCnt = 0;
        }
        if(passCnt > 1){
            printf("White player and Black player can not play anymore.\n");
            break;
        }

        printf("\nput a new %s othello : ", turnColor);
        scanf("%d %d", &userInput[0], &userInput[1]);
        
        if(validateUserInput(turnColor, userInput, gameboard) == 1){
            flipNum = doFlip(turnColor, userInput, gameboard);
            while(canFlip(turnColor, userInput, gameboard) == 1){
                flipNum += doFlip(turnColor, userInput, gameboard);
            }
            if(flipNum > 0){
                changeColor(turnColor);
            }
        }
		
    }
    printOthello(gameboard);
    
    printf("If you exit the program, enter any key.\n");
    scanf("%d", &temp);
    return 0;
}
