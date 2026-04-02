#include <iostream>
#include <queue>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, K;
	cin >> N >> K;

	queue<int> q;
	for (int i = 1; i <= N; i++)
	{
		q.push(i);
	}

	int cnt = K - 1;
	cout << '<';
	while (q.size() > 1)
	{
		if (cnt == 0)
		{
			cnt = K - 1;
			cout << q.front() << ", ";
			q.pop();
		}
		else
		{
			cnt--;
			q.push(q.front());
			q.pop();
		}
	}

	cout << q.front();
	cout << '>';

	return 0;
}
