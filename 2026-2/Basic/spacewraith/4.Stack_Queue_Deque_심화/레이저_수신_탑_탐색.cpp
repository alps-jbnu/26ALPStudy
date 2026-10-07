#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N;

	cin >> N;

	vector<int> towers(N + 1, 0);

	for(int i = 1; i <= N; i++) {
		cin >> towers[i];
	}

	for(int i = 1; i <= N; i++) {
		bool is_blocked = false;

		for(int j = i - 1; j > 0; j--) {
			if(towers[j] >= towers[i]) {
				cout << j << " ";
				is_blocked = true;
				break;
			}
		}

		if(is_blocked) {
			continue;
		} else {
			cout << 0 << ' ';
		}
	}

}
