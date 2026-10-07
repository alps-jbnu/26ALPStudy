#include <iostream>
#include <list>
#include <string>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;

		list<char> L;
		auto cursor = L.end();

		for (char c : s) {
			if (c == '<') {
				if (cursor != L.begin()) cursor--;
			}
			else if (c == '>') {
				if (cursor != L.end()) cursor++;
			}
			else if (c == '-') {
				if (cursor != L.begin()) {
					cursor--;
					cursor = L.erase(cursor);
				}
			}
			else {
				L.insert(cursor, c);
			}
		}

		string ans(L.begin(), L.end());
		cout << ans << '\n';
	}
}
