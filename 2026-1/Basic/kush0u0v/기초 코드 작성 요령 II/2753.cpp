#include <stdio.h>

int main(){
    int yoon;
    scanf("%d", &yoon);
    printf("%d", (yoon % 4 == 0 && yoon % 100 != 0) 
            || (yoon % 400 == 0) ? 1 : 0);
}