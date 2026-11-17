#include <bits/stdc++.h>
using namespace std;
const int MAX = 6561;
char arr[MAX][MAX];

void star(int N, int a, int b) {
	if (N == 3) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (i == 1 && j == 1) arr[a + i][b + j] = ' ';
				else arr[a + i][b + j] = '*';
			}
		}
		return;
	}
	int n3 = N / 3;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i >= n3 && i < n3 * 2 && j >= n3 && j < n3 * 2) arr[a + i][b + j] = ' ';
		}
	}
	star(n3, a, b);
	star(n3, a+n3, b);
	star(n3, a + n3 * 2, b);
	star(n3, a, b+n3);
	star(n3, a+n3 * 2, b+n3);
	star(n3, a, b+n3*2);
	star(n3, a+n3, b+n3*2);
	star(n3, a+n3 * 2, b+n3*2);
	return;
}
int main() {
	int N = 0;
	cin >> N;
	star(N, 0, 0);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << arr[i][j];
		}
		cout << '\n';
	}
	/*for (int i = 6; i < 9; i++) {
		for (int j = 6; j < 9; j++) {
			cout << arr[i][j];
		}
		cout << '\n';
	}*/
	return 0;
}