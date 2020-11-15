#include "util.h"


int getColorToInt(char color[]);
int* getCheckPoint(int userInput[], int toCheckPointValue[]);
void changeColor(char color[]);

int getColorToInt(char color[]) {
    int colorInt = 0;
    if(strcmp(color, "white") == 0){
        colorInt = 1;
    }else{
        colorInt = 2;
    }
    return colorInt;
}

int* getCheckPoint(int userInput[], int toCheckPointValue[]){
    int *result = malloc(sizeof(int) * 2);
    for(int i=0; i<2; i++){
        result[i] = userInput[i] + toCheckPointValue[i];
    }
    return result;
};


void changeColor(char color[]) {
    char blackChar[6] = "black";
    char whiteChar[6] = "white";
    if(strcmp(color, "white") == 0){
        for(int i=0; i<5; i++){
            color[i] = blackChar[i];
        }
    }else{
        for(int i=0; i<5; i++){
            color[i] = whiteChar[i];
        }
    }
};
