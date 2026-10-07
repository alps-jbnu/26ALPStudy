#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string ans;

void find_string(const vector<char> &alpabet, int length, int bound) {
	if(ans.size() == length) {
		int vowel_cnt = 0;
		int conso_cnt = 0;

		for(char c : ans) {
			if(c == 'a' ||c == 'i' ||c == 'u' ||c == 'e' ||c == 'o') 
				vowel_cnt++;
		}
		conso_cnt = ans.size() - vowel_cnt;

		if(vowel_cnt >= 1 && conso_cnt >=2)
			cout << ans << '\n';

		return;
	}

	for(int i = bound; i < alpabet.size(); i++) {

		ans.push_back(alpabet[i]);

		find_string(alpabet, length, i + 1);

		ans.pop_back();
	}

}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int L, C;

	cin >> L >> C;

	vector<char> alpabet(C);
	for(char &c : alpabet) {
		cin >> c;
	}

	sort(alpabet.begin(), alpabet.end());

	find_string(alpabet, L, 0);

	return 0;
}

