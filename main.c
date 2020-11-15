#include <stdio.h>
#include <stdlib.h>

#include "util.h"
#include "othello.h"

int gameboard[N][N];

void main(...)
{
	int userInput[2];
    int flipNum = 0, passCnt=0;
    char turnColor[6] = "white";
    int temp;

	initOthello(gameboard);
    
    while(isGameEnd(gameboard) == 0){
        
        printOthello(gameboard);
        
		// have to check user can play

        printf("\nput a new %s othello : ", turnColor);
        scanf("%d %d", &userInput[0], &userInput[1]);
        
        if(validateUserInput(turnColor, userInput, gameboard) == 1){
            flipNum = doFlip(turnColor, userInput, gameboard);
            while(canFlip(turnColor, userInput, gameboard) == 1){
                flipNum += doFlip(turnColor, userInput, gameboard);
            }
            if(flipNum > 0){
//                printf("%d 개 바뀜.\n", flipNum);
                changeColor(turnColor);
            }
        }
		
    }
    printOthello(gameboard);
    
    printf("If you exit the program, enter any key.\n");
    scanf("%d", &temp);
    return 0;
}


int main(int argc, char *argv[]) {
	return 0;
}
