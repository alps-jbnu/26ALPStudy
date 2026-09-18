#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	int count[10] = {0, };
	
	cin >> N;
	
	do {
		count[N % 10]++;
		N /= 10;
	} while(N);
	
	count[6] += count[9];
	count[6] = (count[6] + 1) / 2;

	int max_idx = 0;
	int max_num = 0;
	for(int i = 0; i <= 8; i++) {
		if(count[i] > max_num) {
			max_idx = i;
			max_num = count[i];
		}
	}

	cout << max_num << '\n';


}
