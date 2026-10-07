#include <stdio.h>


int queue[5001];
int front = 0;
int rear = 0;

void push(int value)
{
    queue[rear] = value;
    rear = (rear + 1) % 5001;
}

int pop(void)
{
    int value = queue[front];
    front = (front + 1) % 5001;
    return value;
}

int main(void)
{
    int N, K;

    scanf("%d %d", &N, &K);

    for (int i = 1; i <= N; i++)
    {
        push(i);
    }

    printf("<");

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < K - 1; j++)
        {
            int temp = pop();
            push(temp);
        }

        int removed = pop();

        printf("%d", removed);

        if (i != N - 1)
        {
            printf(", ");
        }
    }

    printf(">\n");

    return 0;
}
