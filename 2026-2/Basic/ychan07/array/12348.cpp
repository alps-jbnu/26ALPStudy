#include <stdio.h>

int main(void)
{
    int a, b, c;
    long num;
    int count[10] = {0};
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);

    num = a * b * c;

    while (num > 0)
    {
        int digit = num % 10;
        count[digit]++;
        num = num / 10;
    }

    for (int i = 0; i < 10; i++)
    {
        printf("%d\n", count[i]);
    }

    return 0;
}
