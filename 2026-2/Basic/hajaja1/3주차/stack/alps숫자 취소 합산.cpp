#include <stdio.h>

int main() {
	int arr[100000] = {};
	int K = 0;
	scanf("%d", &K);
	int T = 0;
	int tail = 0;
	for (int i = 0; i < K; i++) {
		scanf("%d", &T);
		if (T == 0) {
			tail--;
		}
		else {
			arr[tail++] = T;
		}
	}
	int s = 0;
	for (int j = 0; j < tail; j++)
		s += arr[j];
	printf("%d", s);

	return 0;
}
