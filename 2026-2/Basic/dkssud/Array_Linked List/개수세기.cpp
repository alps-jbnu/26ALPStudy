#include<iostream>
int main() {
	int N;
	int count[250] = { 0 };
	int num;
	int v;
	std::cin >> N;
	for (int i = 0; i < N; i++) {
		std::cin >> num;
		count[num+100]++;
	}
	std::cin >> v;
	std::cout << count[v+100] << "\n";
	return 0;
}
