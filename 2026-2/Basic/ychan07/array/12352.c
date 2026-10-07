#include <stdio.h>

int main(void)
{
    int N;
    char str1[1001];
    char str2[1001];

    scanf("%d", &N);

    for (int t = 0; t < N; t++)
    {
        int count[26] = {0};
        scanf("%s %s", str1, str2);
        for (int i = 0; str1[i] != '\0'; i++)
        {
            count[str1[i] - 'a']++;
        }

        for (int i = 0; str2[i] != '\0'; i++)
        {
            count[str2[i] - 'a']--;
        }

        int possible = 1;
        for (int i = 0; i < 26; i++)
        {
            if (count[i] != 0)
            {
                possible = 0;
                break;
            }
        }

        if (possible)
        {
            printf("Possible\n");
        }
        else
        {
            printf("Impossible\n");
        }
    }

    return 0;
}
