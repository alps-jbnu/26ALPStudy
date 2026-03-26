#include <iostream>
using namespace std;

void InitializeArr(int arr[], const int length);
//int maxValue(int arr[], const int length);
void maxValue(int arr[], const int length, int* retVal, int* maxLoc);

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	
	int arr[9] = { 0 };
	int maxVal, maxLoc;
	const int length = sizeof(arr) / sizeof(arr[0]);

	InitializeArr(arr, length);
	maxValue(arr, length, &maxVal, &maxLoc);

	cout << maxVal << '\n' << maxLoc << '\n';

	return 0;
}

void InitializeArr(int arr[], const int length)
{
	int i;
	for (i = 0; i < length; i++)
		cin >> *(arr + i);
}

int maxValue(int arr[], const int length)
{
	int i, max;
	max = *arr;
	for (i = 0; i < length; i++)
	{
		if (max <= *(arr + i))
		{
			max = *(arr + i);
		}
	}

	return max;

}

void maxValue(int arr[], const int length, int* max, int* loc)
{
	int i;
	*max = *arr;
	for (i = 0; i < length; i++)
	{
		if (*max <= *(arr + i))
		{
			*max = *(arr + i);
			*loc = i + 1;
		}
	}
}

