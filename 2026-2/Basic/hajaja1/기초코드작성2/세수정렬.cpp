#include <stdio.h>

int main(){
    
    int A[3]={0,};
    for(int i = 0 ; i < 3 ; i++)
        scanf("%d", A + i);
    for(int j =0 ;j<2; j++){
        for(int k =0 ;k<2 - j;k++){
            if(A[k] > A[k+1]) {
                int tmp = A[k];
                A[k] = A[k+1];
                A[k+1] = tmp;
            }
        }
    }
    for(int i = 0 ; i < 3 ; i++)
            printf("%d ", *(A+i));
    
}
