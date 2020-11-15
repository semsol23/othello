#include "util.h"


int getColorToInt(char color[]);
int* getCheckPoint(int userInput[], int toCheckPointValue[]);
void changeColor(char color[]);

int getColorToInt(char color[]) {
    int colorInt = 0;
    if(strcmp(color, "white") == 0){ /*문자열 white를 colorInt변수에 1으로 저장*/
        colorInt = 1;
    }else{ /*문자열 black을 colorInt변수에 2로 저장*/
        colorInt = 2;
    }
    return colorInt;
}

int* getCheckPoint(int userInput[], int toCheckPointValue[]){
    int i;
    int *result = malloc(sizeof(int) * 2);
    for(i=0; i<2; i++){
        result[i] = userInput[i] + toCheckPointValue[i];/*행과 열에 대해서 내가 선택한 자리와 더 체크하고 싶은 자리 +*/
    }
    return result;
};


void changeColor(char color[]) {
    int i;
    char blackChar[6] = "black";
    char whiteChar[6] = "white";
    if(strcmp(color, "white") == 0){
        for(i=0; i<5; i++){
            color[i] = blackChar[i]; /*문자열 white를 black으로 변경*/
        }
    }else{
        for(i=0; i<5; i++){
            color[i] = whiteChar[i]; /*문자열 black을 white로 변경*/
        }
    }
};
