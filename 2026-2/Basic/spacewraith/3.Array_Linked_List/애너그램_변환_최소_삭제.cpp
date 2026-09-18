#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string A, B;
	int a_count[26] = {0, };
	int b_count[26] = {0, };
	int result = 0;

	cin >> A >> B; 

	for(char c : A) {
		a_count[c - 'a']++;
	}

	for(char c : B) {
		b_count[c - 'a']++;
	}

	for(int i = 0; i < 26; i++) {
		result += abs(a_count[i] - b_count[i]);
	}

	cout << result << '\n';
}
