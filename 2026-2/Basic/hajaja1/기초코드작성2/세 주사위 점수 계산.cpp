#include <stdio.h>

int main(){
    int A,B,C = 0;
    scanf("%d %d %d", &A,&B,&C);
    if(A == B && B == C){
        printf("%d", 10000 + A*1000);
    }
    else if(A == B || B == C || C == A){
        if(A == B || C == A)
            printf("%d", 1000 + A*100);
        else
            printf("%d", 1000 + C*100);
    }
    else{
        int max = A;
        if(B>=max){
            max = B;
        }
        if(C>=max)
            max = C;
        printf("%d", max*100);
    }
    return 0;
}
