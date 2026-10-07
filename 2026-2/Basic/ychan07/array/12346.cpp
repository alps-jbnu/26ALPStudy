#include <stdio.h>

int main(void) {
    int input;
    int ans[10] = {0};
    int high = 0;

    scanf("%d", &input);

    do {
        ans[input % 10]++;
        input /= 10;
    } while (input > 0);
    ans[6]=ans[6]+ans[9];
    ans[9]=0;
    ans[6]=(ans[6]+1)/2;
    for (int k = 0; k < 10; k++) {
        if (ans[k] > high) {
            high = ans[k];
        }
    }

    printf("%d", high);
    return 0;
}
