#include <iostream>
#include <stack>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	long long result = 0;
	stack<int> towers;

	cin >> N;

	while(N--) {
		int height;

		cin >> height;

		while(!towers.empty() && towers.top() <= height){
			towers.pop();
		}

		result += towers.size();

		towers.push(height);
	}

	cout << result << '\n';
}
