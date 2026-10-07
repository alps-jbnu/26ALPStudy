#include <iostream>
int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::string a, b;
	std::cin >> a >> b;
	int count_a[26] = { 0 };
	int count_b[26] = { 0 };
	int erase_min = 0;
	for (char c : a) {
		count_a[c - 'a']++;
	}
	for (char c : b) {
		count_b[c - 'a']++;
	}
	for (int i = 0; i < 26; i++) {
			erase_min += abs(count_a[i] - count_b[i]); //지워야되는문자개수
	}
	std::cout << erase_min << "\n";
	return 0;
}
