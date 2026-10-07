#include <iostream>
int main() {
	int N;
	int count[10] = {0};
	int six_nine = 0;
	int max = 0;
	std::cin >> N;
	if (N == 0) {
		count[0]++;
	}
	while (N > 0) {
		int digit = N % 10;
		count[digit]++;
		N /= 10;
	}
	six_nine = (count[6] + count[9] + 1) / 2;
	count[6] = six_nine;
	count[9] = six_nine;
	for (int i = 0; i < 10; i++) {
		if (count[i] > max) {
			max = count[i];
		}
	}
	std::cout << max << "\n";
	return 0;
}
