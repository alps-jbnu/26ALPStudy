#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	vector<int> v;
	int sum = 0;
	for (int i = 0; i < 7; i++)
	{
		int num;
		cin >> num;

		if (num % 2 == 1)
		{
			sum += num;
			v.push_back(num);
		}
	}

	if (v.empty())
	{
		cout << -1 << "\n";
		return 0;
	}

	int result = 101;
	for (int i : v)
	{
		if (result > i)
		{
			result = i;
		}
	}

	cout << sum << "\n";
	cout << result << "\n";

	return 0;
}
