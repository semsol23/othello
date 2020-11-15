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
        
		
    }
    printOthello(gameboard);
    
    printf("If you exit the program, enter any key.\n");
    scanf("%d", &temp);
    return 0;
}


int main(int argc, char *argv[]) {
	return 0;
}
