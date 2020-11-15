#ifndef util_h
#define util_h

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int getColorToInt(char color[]);
int* getCheckPoint(int userInput[], int toCheckPointValue[]);
void changeColor(char color[]);

#endif /* util_h */