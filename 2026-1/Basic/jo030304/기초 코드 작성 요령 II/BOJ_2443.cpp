#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	int i, j, k;
	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= i - 1; j++)
		{
			cout << " ";
		}
		for (k = 0; k < 2 * N - 2 * i + 1; k++)
		{
			cout << '*';
		}
		cout << "\n";
	}

	return 0;
}
