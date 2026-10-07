#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N = 0, L = 0;
	cin >> N >> L;
	
	deque<pair<int, int>> dq;
	for(int i = 0; i < N; i++) {
			int num = 0;
			cin >> num;
			
			if(!dq.empty() && i - dq.front().second >= L) {
					dq.pop_front();
			}

			while(!dq.empty() && dq.back().first >= num) {
					dq.pop_back();
			}

			dq.push_back({num, i});

			cout << dq.front().first << ' ';
	}

	cout << '\n';
	
	return 0;
}
