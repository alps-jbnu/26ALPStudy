#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<int> v(n, 0);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	int x;
	cin >> x;

	sort(v.begin(), v.end());

	int left = 0, right = n - 1, result = 0;
	while (left < right)
	{
		int sum = v[left] + v[right];

		if (sum == x)
		{
			result++;
			left++;
			right--;
		}
		else if (sum < x)
		{
			left++;
		}
		else
		{
			right--;
		}
	}

	cout << result << "\n";

	return 0;
}
