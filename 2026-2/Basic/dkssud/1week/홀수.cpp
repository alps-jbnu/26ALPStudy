#include <iostream>
int main() {
	int arr[10];
	int odd[10];
	int odd_sum = 0;
	int odd_min = 100;
	for (int i = 0; i < 7; i++) {
		std::cin >> arr[i];
		if (arr[i] % 2 != 0) {//홀수
			odd[i] = arr[i];
			odd_sum += odd[i]; //홀수 합
			if (odd[i] < odd_min) {
				odd_min = odd[i]; //홀수 최솟값
			}
		}
		
	}
	if (odd_sum != 0) { //홀수 있
		std::cout << odd_sum << "\n" << odd_min << "\n";
	}
	else { //홀수 없
		std::cout << -1 << "\n";
	}
	return 0;
}
