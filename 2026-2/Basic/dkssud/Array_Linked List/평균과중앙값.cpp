#include<iostream>
int main() {
	int arr[10];
	int sum = 0;
	for (int i = 0; i < 5; i++) {
		std::cin >> arr[i];
		sum += arr[i];
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (arr[i] > arr[j]) {
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	std::cout << sum / 5 << "\n";
	std::cout << arr[2] << "\n";
}
