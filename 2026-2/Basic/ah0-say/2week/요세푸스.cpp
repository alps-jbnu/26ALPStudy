#include <iostream>
using namespace std;

int arr[5005];

void erase(int idx, int arr[], int& len) {
	len--;
	for (int i = idx; i < len; i++)
		arr[i] = arr[i + 1];
}

int main(void) {
	int n, k;
	cin >> n >> k;

	int len = n;
	for (int i = 0; i < n; i++) arr[i] = i + 1;

	int idx = 0;
	cout << '<';
	while (len > 0) {
		idx = (idx + k - 1) % len;
		cout << arr[idx];
		erase(idx, arr, len);
		if (len > 0) cout << ", ";
	}
	cout << '>';
}
