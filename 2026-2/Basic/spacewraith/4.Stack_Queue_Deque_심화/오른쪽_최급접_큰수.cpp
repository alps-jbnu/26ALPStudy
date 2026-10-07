#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N = 0;

	cin >> N;

	vector<int> elements(N, 0);
	vector<int> NGE(N, 0);
	stack<int> S;

	for(int i = 0; i < N; i++) {
		cin >> elements[i];
	}


	for(int i = 0; i < N; i++) {
		
		while(!S.empty() && elements[S.top()] < elements[i]) {
			NGE[S.top()] = elements[i];
			S.pop();
		}

		S.push(i);
	}

	while(!S.empty()) {
		NGE[S.top()] = -1;
		S.pop();
	}

	for(int i : NGE) {
		cout << i << " ";
	}

	cout << '\n';

	return 0;
}
