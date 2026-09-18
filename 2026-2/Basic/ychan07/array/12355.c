#include <stdio.h>

#define MAX 1000001

char input[MAX];
char left[MAX];
char right[MAX];

int main(void)
{
    int T;

    scanf("%d", &T);

    while (T--)
    {
        scanf("%s", input);

        int lTop = 0;
        int rTop = 0;

        for (int i = 0; input[i] != '\0'; i++)
        {
            char ch = input[i];

            if (ch == '<')
            {
                if (lTop > 0)
                {
                    right[rTop++] = left[--lTop];
                }
            }
            else if (ch == '>')
            {
                if (rTop > 0)
                {
                    left[lTop++] = right[--rTop];
                }
            }
            else if (ch == '-')
            {
                if (lTop > 0)
                {
                    lTop--;
                }
            }
            else
            {
                left[lTop++] = ch;
            }
        }

        for (int i = 0; i < lTop; i++)
        {
            putchar(left[i]);
        }

        for (int i = rTop - 1; i >= 0; i--)
        {
            putchar(right[i]);
        }

        putchar('\n');
    }

    return 0;
}
