#include <stdio.h>

int arr[1000005];
int result[1000005];
int stack[1000005];
int top = -1;

int main() 
{
    int n;
    if (scanf("%d", &n) != 1) 
    
    return 0;
    
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &arr[i]);
    }
    
    for (int i = n - 1; i >= 0; --i) 
    {
        while (top >= 0 && arr[stack[top]] <= arr[i]) 
        {
            top--;
        }
        
        if (top >= 0) {
            result[i] = arr[stack[top]];
        } else {
            result[i] = -1;
        }
        
        stack[++top] = i;
    }
    for (int i = 0; i < n; ++i) {
        printf("%d%s", result[i], (i == n - 1) ? "" : " ");
    }
    printf("\n");
    
    return 0;
}
