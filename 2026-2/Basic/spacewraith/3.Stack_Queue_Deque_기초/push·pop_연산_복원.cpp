#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	int next_num = 1;
	vector<char> result;
	stack<int> S;

	cin >> n;

	while(n--) {
		int num;
		cin >> num;

		while(num >= next_num) {
			S.push(next_num++);
			result.push_back('+');
		}

		if(!S.empty() && S.top() == num) {
			S.pop();
			result.push_back('-');
		} else {
			cout << "NO\n";
			return 0;
		}
	}

	for(char c : result)
		cout << c << '\n';

}
