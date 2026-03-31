#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int A, B, C;
	cin >> A >> B >> C;

	vector<int> v(10, 0);

	int result = A * B * C;
	while (result)
	{
		v[result % 10]++;
		result /= 10;
	}

	for (int i : v)
	{
		cout << i << "\n";
	}

	return 0;
}
