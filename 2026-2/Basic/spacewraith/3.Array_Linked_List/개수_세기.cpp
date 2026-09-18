#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;
	
	vector<int> arr(N);
	
	for(int& i: arr) {
		cin >> i;
	}

	int v;
	cin >> v;

	cout << count(arr.begin(), arr.end(), v);

}
