#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	stack<int> s;
	vector<char> result;
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;

		while (num > cnt && n > cnt)
		{
			++cnt;
			s.push(cnt);
			result.push_back('+');
		}
		if (!s.empty() && s.top() == num)
		{
			s.pop();
			result.push_back('-');
		}
		else
		{
			cout << "NO" << "\n";
			return 0;
		}
	}

	for (char c : result)
	{
		cout << c << "\n";
	}

	return 0;
}
