#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	stack<vector<int>> towers;

	cin >> N;

	for(int i = 1; i <= N; i++) {
		vector<int> tower(2);
		tower[0] = i;
		cin >> tower[1];

		while(!towers.empty() && towers.top()[1] < tower[1]) {
			towers.pop();
		}

		if(towers.empty()) {
			cout << 0 << ' ';
		} else {
			cout << towers.top()[0] << ' ';
		}

		towers.push(tower);
	}
}
