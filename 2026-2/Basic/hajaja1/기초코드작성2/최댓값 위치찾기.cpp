#include <stdio.h>

int main(){
    
    int num;
    int idx =0;
    int max = 0;
    for(int i=0;i<9;i++){
        scanf("%d", &num);
        if(max < num){
            max = num;
            idx = i+1;
        }
    }
        printf("%d\n%d", max, idx);
}
