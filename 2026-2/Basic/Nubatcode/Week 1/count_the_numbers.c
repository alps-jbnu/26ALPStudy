#include <stdio.h>

void main(){
    int a = 0, b = 0, c = 0, result = 0;
    int i = 0;
    char count[10] = {0, };

    scanf("%d %d %d", &a, &b, &c);
    result = a * b * c;
    
    while(result > 0){
        i = result%10;
        count[i]++;
        result = result/10;
    }

    for(int i = 0; i < sizeof(count); i++) printf("%d\n", count[i]);
}
