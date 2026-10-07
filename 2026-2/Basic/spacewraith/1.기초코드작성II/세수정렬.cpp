#include <iostream>
#include <vector>
#include <algorithm>

#define INT_COUNT 3

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<int> arr(INT_COUNT);

	for(int& i: arr) {
		cin >> i;
	}


	sort(arr.begin(), arr.end());

	for(int i: arr) {
		cout << i << ' ';
	}
}
