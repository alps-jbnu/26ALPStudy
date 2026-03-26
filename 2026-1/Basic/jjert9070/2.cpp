#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int func2(int arr[], int N);


int main()
{
	int arr1[] = {1, 52, 48};
	int arr2[] = {50, 42};
	int arr3[] = {4, 13, 63, 87};
	cout << func2(arr1, 3) << endl;
	cout << func2(arr2, 2) << endl;
	cout << func2(arr3, 4) << endl;

	

	return 0;
}

int func2(int arr[], int N)
{
	int i, j;
	for (i = 0; i < N-1; i++)
	{ // N - 1회 전체 반복
		for (j = i + 1; j < N; j++)
		{ // N회 반복
			if ((*(arr + i) + *(arr + j)) == 100) // 1 + 1 + 1 + 1 + 1 + 1 = 6
			{
				return 1;
			}
		}
	}
	// (N-1)*{(N-1)*6} = (N-1){6(N-1)} = 6(N-1)^2 = O(N^2)
	return 0;
}