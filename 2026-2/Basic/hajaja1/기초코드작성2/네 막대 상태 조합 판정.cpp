#include <stdio.h>

int main(){
    
    for(int j=0;j<3;j++){
        int A = 0;
        int n = 0;
        for(int i = 0; i < 4; i++) {
            scanf("%d", &n);
            if(n==0)
                A++;
        }
        if(A==0)
            printf("E");
        else if(A==1)
            printf("A");
        else if(A==2)
            printf("B");
        else if(A==3)
            printf("C");
        else
            printf("D");
        printf("\n");
    }
    return 0;
}
