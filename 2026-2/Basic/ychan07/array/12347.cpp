#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    char input1[1001];
    char input2[1001];

    int count1[26] = {0};
    int count2[26] = {0};

    scanf("%s", input1);
    scanf("%s", input2);

    for (int i = 0; input1[i] != '\0'; i++)
    {
        count1[input1[i] - 'a']++;
    }

    for (int i = 0; input2[i] != '\0'; i++)
    {
        count2[input2[i] - 'a']++;
    }

    int answer = 0;

    for (int i = 0; i < 26; i++)
    {
        answer += abs(count1[i] - count2[i]);
    }

    printf("%d\n", answer);

    return 0;
}
