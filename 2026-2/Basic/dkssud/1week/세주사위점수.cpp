#include <iostream>
int main() {
	int a, b, c;
	int same = 0;
	int max = 0;
	std::cin >> a >> b >> c;
	if (a == b && b == c) {
		std::cout << 10000 + (a * 1000) << std::endl;
	}
	else if ((a == b) || (b == c) || (c == a)) {
		if (a == b) {
			same = a;
		}
		else if (b == c) {
			same = b;
		}
		else {
			same = c;
		}
		std::cout << 1000 + (same * 100) << std::endl;
	}
	else {
		if (a > b && a > c) {
			max = a;
		}
		else if (b > c) {
			max = b;
		}
		else {
			max = c;
		}
		std::cout << max * 100 << std::endl;
	}
}
