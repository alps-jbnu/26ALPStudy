#include <iostream>
#include <utility>
#include <stack>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	stack<pair<int, int>> towers;

	cin >> N;

	for(int i = 1; i <= N; i++) {
		pair<int, int> tower;
		tower.first = i;
		cin >> tower.second;

		while(!towers.empty() && towers.top().second < tower.second) {
			towers.pop();
		}

		if(towers.empty()) {
			cout << 0 << ' ';
		} else {
			cout << towers.top().first << ' ';
		}

		towers.push(tower);
	}
}
