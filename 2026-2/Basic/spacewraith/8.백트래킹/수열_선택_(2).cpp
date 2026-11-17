#include <iostream>
#include <vector>

using namespace std;

vector<int> seq;

void find_seq(int n, int m, int bound) {
	if(seq.size() == m) {
		for(int i : seq) {
			cout << i << ' ';
		}
		
		cout << '\n';

		return;
	}

	for(int i = bound; i <= n; i++) {
		seq.push_back(i);
		find_seq(n, m, i + 1);
		seq.pop_back();
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;

	cin >> n >> m;

	find_seq(n, m, 1);

	return 0;
}

