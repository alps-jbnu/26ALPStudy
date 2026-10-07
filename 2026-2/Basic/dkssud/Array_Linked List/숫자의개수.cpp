#include<iostream>
#include <string>
int main() {
	int A, B, C;
	int count[15] = { 0 };
	std::cin >> A >> B >> C;
	std::string T;
	T = std::to_string(A * B * C); //정수를 문자열로 변환(std::to_string)
	for (char c : T) {
		count[c - '0']++;
	}
	for (int i = 0; i < 10; i++) {
		std::cout << count[i] << "\n";
	}
	return 0;
}
