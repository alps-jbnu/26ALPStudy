#include <bits/stdc++.h>

using namespace std;

vector<int> seq;

void find_seq(int n, int m, int bound) {
	if (seq.size() == m) {
		for (int i : seq) {
			cout << i << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = bound; i <= n; i++) {
		seq.push_back(i);
		find_seq(n, m, i + 1);
		seq.pop_back();
	}
}

int main() {
	int n = 0, m = 0;
	cin >> n >> m;
	find_seq(n, m, 1);
	return 0;
}