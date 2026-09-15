#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string S;
	int count[26] = {0, };

	cin >> S;

	for(int c : S) {
		count[c - 'a']++;
	}


	for(int i: count) {
		cout << i << ' ';
	}

	cout << '\n';
}
