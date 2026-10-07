#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int num;
	int max_num = 0;
	int max_idx = 0;

	for(int i = 1; i <= 9; i++) {
		cin >> num;

		if(num > max_num) {
			max_num = num;
			max_idx = i;
		}
	}

	cout << max_num << '\n';
	cout << max_idx << '\n';

	return 0;
}
