#include <iostream>
int main() {
	int arr[3][4];
	int count_0 = 0;
	int count_1 = 0;
	for (int i = 0; i < 3; i++) { //입력
		for (int j = 0; j < 4; j++) {
			std::cin >> arr[i][j];
		}
	}
	for (int i = 0; i < 3; i++) {
		count_0 = 0; //초기화
		count_1 = 0;
		for (int j = 0; j < 4; j++) {
			if (arr[i][j] == 0) {
				count_0++;
			}
			else {
				count_1++;
			}
		}
		if (count_0 == 1) {
			std::cout << "A" << "\n";
		}
		else if (count_0 == 2) {
			std::cout << "B" << "\n";
		}
		else  if (count_0 == 3) {
			std::cout << "C" << "\n";
		}
		else if (count_0 == 4) {
			std::cout << "D" << "\n";
		}
		else {
			std::cout << "E" << "\n";
		}
	}
	return 0;
}
