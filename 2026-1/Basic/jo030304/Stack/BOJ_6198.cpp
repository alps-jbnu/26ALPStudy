#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	// 거꾸로 입력
	vector<int> v(N);
	for (int i = N - 1; i >= 0; i--)
	{
		cin >> v[i];
	}

	// 누적합(큰 값만 관리)
	long long result = 0;
	stack<pair<int, long long>> s;
	for (int i = 0; i < N; i++)
	{
		int cnt = 0;
		while (!s.empty() && s.top().first < v[i])
		{
			cnt++;
			cnt += s.top().second;
			s.pop();
		}

		result += cnt;

		s.push({ v[i], cnt });
	}

	cout << result << "\n";

	return 0;
}
