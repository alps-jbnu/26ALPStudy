#include <bits/stdc++.h>
using namespace std;

int arr[128][128]; //최대 64by64인 행렬

int one=0, zero=0;

void quadra(int N, int a, int b) { // 행렬의 한변의 길이 N과 시작 좌표 a,b

	if (N == 1) {
		switch (arr[a][b]) { // 행열의 길이가 1이면 요소의 값을 큐에 바로 넣음
		case  0: zero++;  return;
		case  1: one++;  return;
		}
	}
	bool same = true;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[a][b] != arr[a + i][b + j]) {
				same = false; break;
			}
		}
		if (!same)break;
	}
	if (same) {
		switch (arr[a][b]) {
		case  0: zero++;  return;
		case  1: one++;  return;
		}
	}
	else {
		int n4 = N / 2;
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				quadra(n4, a + n4 * i, b + n4 * j);
			}
		}
	}
	return;
}

int main() {
	int N = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}
	/*for (int i = 0; i < N; i++) {
		cout << arr[i] <<'\n';
	}*/
	quadra(N, 0, 0);
	cout << zero<<'\n'<<one;
	return 0;
}