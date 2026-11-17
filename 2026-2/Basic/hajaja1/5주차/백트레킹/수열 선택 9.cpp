#include <bits/stdc++.h>

using namespace std;

int n, m;
int arr[8];
vector<int> seq;
bool isused[8];

void find_seq(int bound) {

	if (bound == m) {
		for (int i : seq) {
			cout << i << ' ';
		}
		cout << '\n';
		return;
	}
	int prev = -1; // 같은 깊이(depth)에서 이미 시도한 값인지 확인용

	for (int i = 0; i < n; i++) {
		if (!isused[i]) {
			// 이번 깊이에서 방금 선택했던 값과 같다면 중복 출력을 막기 위해 건너뜀
			if (prev == arr[i]) continue;

			isused[i] = true;
			seq.push_back(arr[i]);
			prev = arr[i]; // 현재 값을 prev에 기록

			find_seq(bound + 1);
			seq.pop_back();
			isused[i] = false;
		}
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
	find_seq(0);
	return 0;
}
