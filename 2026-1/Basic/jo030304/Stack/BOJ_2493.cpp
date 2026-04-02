#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	stack<pair<int, int>> s;
	vector<int> result;
	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;

		while (!s.empty() && s.top().first < num)
		{
			s.pop();
		}

		if (!s.empty())
		{
			result.push_back(s.top().second);
		}
		else
		{
			result.push_back(0);
		}

		s.push({ num, i + 1 });
	}

	for (int a : result)
	{
		cout << a << " ";
	}
	cout << "\n";

	return 0;
}
