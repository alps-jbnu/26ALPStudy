#include <iostream>
#include <stack>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		stack<char> L, R;
		string s;
		cin >> s;

		for (char c : s)
		{
			if (c == '<')
			{
				if (L.empty())
				{
					continue;
				}

				R.push(L.top());
				L.pop();
			}
			else if (c == '>')
			{
				if (R.empty())
				{
					continue;
				}

				L.push(R.top());
				R.pop();
			}
			else if (c == '-')
			{
				if (L.empty())
				{
					continue;
				}

				L.pop();
			}
			else
			{
				L.push(c);
			}
		}
		
		// 출력
		while (!L.empty())
		{
			R.push(L.top());
			L.pop();
		}

		while (!R.empty())
		{
			cout << R.top();
			R.pop();
		}
		cout << "\n";
	}

	return 0;
}
