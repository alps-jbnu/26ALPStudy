#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

int main()
{
	int arr[4];
	for (int i = 0; i < 3; i++)
	{
		scanf("%d %d %d %d", &arr[0], &arr[1], &arr[2], &arr[3]);
		int count = 0;
		for (int j = 0; j < 4; j++)
		{
			if (arr[j] == 0)
				count++;
		}
		if (count == 1)
			printf("A\n");
		else if (count == 2)
			printf("B\n");
		else if (count == 3)
			printf("C\n");
		else if (count == 4)
			printf("D\n");
		else
			printf("E\n");
	}
	return 0;
}
