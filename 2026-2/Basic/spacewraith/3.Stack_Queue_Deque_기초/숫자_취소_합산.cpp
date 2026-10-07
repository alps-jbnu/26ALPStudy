#include <iostream>
#include <stack>

using namespace std;

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	stack<int> s;
	int k;

	cin >> k;

	while(k--) {
		int input;

		cin >> input;

		if(input == 0) {
			s.pop();
		} else {
			s.push(input);
		}
	}

	int sum = 0;
	while(!s.empty()) {
		sum += s.top();
		s.pop();
	}

	cout << sum << '\n';
}
