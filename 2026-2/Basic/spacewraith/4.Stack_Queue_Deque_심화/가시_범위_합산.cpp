#include <iostream>
#include <stack>
#include <utility>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N = 0;
	int result = 0;
	stack<int> towers;
	stack<pair<int, int>> S;

	cin >> N;

	while(N--) {
		int height = 0;

		cin >> height;

		towers.push(height);
	}

	while(!towers.empty()) {
		int visible = 0;
		int height = towers.top();
		towers.pop();

		while(!S.empty() && S.top().first < height) {
			visible += S.top().second + 1;
			S.pop();
		}

		result += visible;
		S.push(make_pair(height, visible));
	}
	
	cout << result << '\n';
}
