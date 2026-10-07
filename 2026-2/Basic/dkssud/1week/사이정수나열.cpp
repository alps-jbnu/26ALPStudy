#include <iostream>
int main() {
	int A, B;
	int count = 0;
	std::cin >> A >> B;
	if (A > B) { //A가 B보다 크면 자리바꿈
		int temp = A;
		A = B;
		B = temp;
	}
		count = B - A - 1;
		if (count == 0 || count == -1) { //개수가 0이거나 두 정수가 같은 값
			std::cout << '0' << "\n";
		}
		else {
			std::cout << count << "\n";
		}
		for (int i = 1; i <= count; i++) {
			std::cout << A + i << " ";
		}
		return 0;
}
