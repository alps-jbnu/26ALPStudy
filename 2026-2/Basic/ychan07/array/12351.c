#include <stdio.h>
int main(void)
{
    char a[101];
    int count[26] = {0};

    scanf("%s", a);

    for (int i = 0; a[i] != '\0'; i++)
    {
        count[a[i] - 'a']++;
    }

    for (int i = 0; i < 26; i++)
    {
        printf("%d ", count[i]);
    }

    return 0;
}
