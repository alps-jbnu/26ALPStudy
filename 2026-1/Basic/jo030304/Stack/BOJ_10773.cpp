#include <iostream>
#include <stack>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int K;
	cin >> K;

	stack<int> s;
	for (int i = 0; i < K; i++)
	{
		int num;
		cin >> num;

		if (num != 0)
		{
			s.push(num);
		}
		else if(num == 0 && !s.empty())
		{
			s.pop();
		}
	}

	int result = 0;
	while (!s.empty())
	{
		result += s.top();
		s.pop();
	}

	cout << result << "\n";

	return 0;
}
