#include <iostream>
int main() {
	int arr[10];
	int max = 0;
	int max_index = 0;
	for (int i = 1; i < 10; i++) {
		std::cin >> arr[i];
		if (arr[i] > max) {
			max = arr[i]; //최댓값
			max_index = i; //최댓값 인덱스
		}
	}
	std::cout << max << "\n" << max_index << "\n";
	return 0;
}
