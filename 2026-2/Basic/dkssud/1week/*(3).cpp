#include <iostream>
int main() {
	int N;
	std::cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < N - i + 1; j++) {
			std::cout << "*";
		}
		std::cout << "\n";
	}
	return 0;
}
