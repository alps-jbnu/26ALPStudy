#include <iostream>
using namespace std;
int main()
{
	int i, j;
	int n;
	cin >> n;

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < i; j++)
			cout << ' ';
		for (j = 0; j < 2*n - 2 * i - 1; j++)
			cout << '*';
		cout << '\n';
	}

	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - 1 - i - 1; j++)
			cout << ' ';
		for (j = 0; j < 3 + 2*i; j++)
			cout << '*';
		cout << '\n';
	}
	
}