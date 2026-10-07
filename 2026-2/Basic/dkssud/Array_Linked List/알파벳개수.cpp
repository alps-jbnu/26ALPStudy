#include<iostream>
#include<string>
int main() {
	std::string S;
	std::cin >> S;
	int count[26] = { 0 };
	for (char c : S) {
		count[c - 'a']++;
	}
	for (int i = 0; i < 26; i++) {
		std::cout << count[i] << " ";
	}
}
