#include <stdio.h>

int main(){
    
    int arr[7] ={0,};
    int s = 0;
    int flag =0;
    for(int i=0;i<7;i++){
        scanf("%d", &arr[i]);
        if(arr[i]%2 == 1){
            s += arr[i];
            flag++;
        }
    }
    int min = 1000000;
    for(int i=0;i<7;i++){
        if(arr[i]%2 == 1){
            if(min>=arr[i])
                min = arr[i];
        }
    }
    if(flag >= 1)
        printf("%d\n%d", s, min);
    else
        printf("-1");
}
