#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	vector<int> v(10, 0);
	while (N)
	{
		v[N % 10]++;
		N /= 10;
	}

	// 6, 9 조건
	if ((v[6] + v[9]) % 2 == 1)
	{
		v[9] = (v[9] + v[6]) / 2 + 1;
		v[6] = 0;
	}
	else
	{
		v[9] = (v[9] + v[6]) / 2;
		v[6] = 0;
	}

	cout << *max_element(v.begin(), v.end());

	return 0;
}
