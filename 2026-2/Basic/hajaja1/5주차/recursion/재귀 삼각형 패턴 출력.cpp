#include <bits/stdc++.h>
using namespace std;
char arr[3 * 1024][3 * 1024 * 2 - 1];
void triangle(int N,int a,int b) {
	if (N == 3) {
		arr[a][b] = '*';
		arr[a+1][b-1] = '*';
		arr[a+1][b+1] = '*';
		for (int i = 0; i < 5; i++) {
			arr[a + 2][b - 2 + i] = '*';
		}
		return;
	}
	int n2 = N / 2;
	triangle(n2,a, b);
	triangle(n2, a+n2, b - n2);
	triangle(n2, a+n2, b + n2 );
	return;
}

int main() {
	for (int i = 0; i < 3 * 1024; i++) {
		for (int j = 0; j < 3 * 1024 * 2 - 1; j++) {
			arr[i][j] = ' ';
		}
	}
	int N = 0;
	cin >> N;

	triangle(N, 0, N-1);
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N * 2 - 1; j++) {
			cout << arr[i][j];
		}
		cout << '\n';
	}
	return 0;
}