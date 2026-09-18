#include <iostream>
#include <algorithm>

const int ARR_SIZE = 5;

using namespace std;

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int sum = 0;
	int arr[ARR_SIZE];

	for(int& i : arr) {
		cin >> i;
		sum += i;
	}

	sort(arr, arr + ARR_SIZE);

	cout << sum / ARR_SIZE << '\n';
	cout << arr[ARR_SIZE / 2] << '\n';
	
}
