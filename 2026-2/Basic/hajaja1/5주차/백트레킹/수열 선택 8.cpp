#include <bits/stdc++.h>

using namespace std;

int n, m;
int arr[8];
vector<int> seq;
bool isused[8];

void find_seq(int bound) {

	if (seq.size() == m) {
		for (int i : seq) {
			cout << i << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = bound; i <= n; i++) {
			seq.push_back(arr[i - 1]);
			find_seq(i);
			seq.pop_back();
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int tmp = 0;

	for (int i = 0; i < n - 1; i++) { // 오름 차순 정렬
		for (int j = 0; j < n - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
	find_seq(1);
	return 0;
}
