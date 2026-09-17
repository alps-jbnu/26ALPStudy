#include <stdio.h>

int main(){
    int A = 0;
    scanf("%d", &A);
    for(int j=1;j<=A;j++){
        for(int i=1;i<=A-j;i++)
            printf(" ");
        for(int i=1;i<=j;i++){
            printf("*");
    }
        printf("\n");
    }
    return 0;
}
