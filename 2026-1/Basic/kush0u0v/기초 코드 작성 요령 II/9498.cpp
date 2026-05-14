#include <stdio.h>
char compair(int a){
    char rank;
    int b = a / 10;
    switch (b){
        case 10 : rank = 'A'; break;
        case 9 : rank = 'A'; break;
        case 8 : rank = 'B'; break;
        case 7 : rank = 'C'; break;
        case 6 : rank = 'D'; break;
        default : rank = 'F'; break;
    } return rank;
}
int main() {
    int a;
    scanf("%d", &a);
    printf("%c", compair(a));
    return 0;
}
