#include <stdio.h>

int main() {
	int a[5] = {};
	for (int i = 0; i < 5; i++) {
		scanf("%d", a + i);
	}
	int temp = 0;
	for (int i = 0; i < 4; i++) { // 내림차순 정렬
		for (int j = 0; j < 5-i-1; j++) {
			if (a[j + 1] > a[j]) {
				temp = a[j + 1];
				a[j + 1] = a[j];
				a[j] = temp;
			}
		}
	}
	int ave = (a[0] + a[1] + a[2] + a[3] + a[4]) / 5;
	printf("%d\n%d", ave, a[2]);
	return 0;
}