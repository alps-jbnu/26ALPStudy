#include <iostream>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int num;
	int count[7] = {0, };

	for(int i = 0; i < 3; i++) {
		cin >> num;
		count[num]++;
	}


	int max_num = 0;
	int max_count = 0;
	for(int i = 1; i <= 6; i++) {
		if(count[i] >= max_count) {
			max_count = count[i];
			max_num = i;
		}
	}


	switch(max_count) {
		case 1:
			cout << max_num * 100;
			break;
		case 2:
			cout << 1000 + max_num * 100;
			break;
		case 3:
			cout << 10000 + max_num * 1000;
			break;
	}

	return 0;
}
