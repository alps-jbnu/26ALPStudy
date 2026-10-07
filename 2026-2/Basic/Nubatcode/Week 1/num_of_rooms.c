// code by Bryson
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int room_number = 0, count = 0;
    scanf("%d", &room_number);
    int len = snprintf(NULL, 0, "%d", room_number);
    int N[len], n[10] = {0, };
    // Number into digits
    for(int i = 0; i < len; i++){
        N[i] = room_number % 10;
        room_number = room_number / 10;
    }
    // Summarizing
    for(int i = 0; i < len; i++){
        if(N[i] == 6) n[9]++;
        else n[N[i]]++;
    }
    // Count necessary sets
    for(int i = 0; i < 10; i++){
        if(count < n[i]){
            if(i == 9){
                count = (n[9] + 1) / 2;
            }else count = n[i];
        }
    }
    printf("%d", count);
    return 0;
}

