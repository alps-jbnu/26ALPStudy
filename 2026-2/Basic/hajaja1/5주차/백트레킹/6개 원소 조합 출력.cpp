#include <bits/stdc++.h>
using namespace std;

int arr[15];
int boxarr[15];
int k;
bool isused[15];

void combination(int bound, int depth) {
	if (depth == 6) {
		for (int i = 0; i < 6; i++) {
			cout << boxarr[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = bound; i <= k; i++) {
		boxarr[depth] = arr[i];
		combination(i + 1, depth + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	bool first = true;
	while (cin >> k && k != 0) { // k가 0이 아닐때 까지 반복
		for (int i = 1; i <= k; i++) {
			cin >> arr[i];
		}
		if(!first)
		cout << '\n';
		first = false;
		combination(1, 0);
	}
	return 0;
}