#ifndef othello_h
#define othello_h
#define N 6

#include <stdio.h>

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

#endif /* othello_h */
