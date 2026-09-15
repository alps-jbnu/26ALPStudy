#include <iostream>

using namespace std;

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int num;
	int min_odd = 100;
	int sum_odd = 0;

	for(int i = 0; i < 7; i++) {
		cin >> num;

		if(num % 2 == 1) {
			sum_odd += num;

			if(num < min_odd)
				min_odd = num;
		}
	}

	if(sum_odd == 0) {
		cout << -1;
	} else {
		cout << sum_odd << '\n';
		cout << min_odd << '\n';
	}

	return 0;
}
