#include <stdio.h>

int main(){
    int A = 0;
    scanf("%d", &A);
    for(int j=1;j<=A;j++){
        for(int i=A;i>=j;i--){
            printf("*");
    }
        printf("\n");
    }
    return 0;
}
