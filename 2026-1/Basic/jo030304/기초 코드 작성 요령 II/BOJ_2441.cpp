#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j < i - 1; j++)
		{
			cout << " ";
		}
		for (int k = 0; k < N - i + 1; k++)
		{
			cout << '*';
		}
		cout << "\n";
	}

	return 0;
}
