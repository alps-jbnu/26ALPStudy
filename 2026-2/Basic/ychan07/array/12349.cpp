#include <stdio.h>
int swap(int *a, int *b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
int main(void){
    int input[5];
    int total=0;
    int average;
    for(int i=0; i<5; i++){
        scanf("%d", &input[i]);
        total=total+input[i];
    }
    average=total/5;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4 - i; j++)
        {
            if (input[j] > input[j + 1])
            {
                swap(&input[j], &input[j + 1]);
            }
        }
    }
    printf("%d\n", average);
    printf("%d", input[2]);


    return 0;
}
