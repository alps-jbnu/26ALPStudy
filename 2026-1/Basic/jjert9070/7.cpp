#include <iostream>
using namespace std;

void printStar(int n);

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	int n;
	cin >> n;
	printStar(n);

}

void printStar(int n)
{
	int i, j;
	int incr = 0;
	bool flag = false;
	for (i = 0; i < n; i++) // 전체 횟수 2*n - 1 
	{
		for (j = 0; j < i + 1; j++)
		{
			cout << '*';
		}

		for (j = 0; j < (2 * n) - 2*(i+1); j++)
		{
			cout << ' ';
		}
		for (j = 0; j < i + incr + 1; j++)
		{
			cout << '*';
		}
		cout << '\n';
	}

	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - i - 1; j++)
		{
			cout << '*';
		}
		for (j = 0; j < 2 * n - 2 * (n - i - 1); j++)
		{
			cout << ' ';
		}
		for (j = 0; j < n - i - 1; j++)
		{
			cout << '*';
		}
		cout << '\n';
	}
}