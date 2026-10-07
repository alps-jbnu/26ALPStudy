#include <stdio.h>

int main() {
	int n = 0;
	scanf("%d", &n);
	int arr[100000] = {};
	char arr2[100001] = {};
	int cur = 0; //일단 0으로 해서 n이 1일때도 넣을 수 있게함
	int tail = 0; // 스택 push할 자리
	int tail2 = 0;
	int N = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &N);
		if (cur < N) {
			for (int j = cur; j < N; j++) {
				arr[tail++] = ++cur; //횟수 만큼 넣음
				arr2[tail2++] = '+'; //push 기록
				/*printf("+\n");
				printf("%d\n",cur);*/
			}
			arr2[tail2++] = '-'; //pop
			tail--; //pop
			/*printf("%d\n", arr[tail - 1]);
			printf("-1\n-----\n");*/
		}
		else {
			if (arr[tail - 1] != N) {
				printf("NO");
				return 0;
			}
			else if (arr[tail - 1] == N) {
				arr2[tail2++] = '-'; //pop
				tail--; //pop
				/*printf("-2\n-----\n");*/
			}
		}
	}
	for (int j = 0; j < tail2; j++)
		printf("%c\n", arr2[j]);
	return 0;

	/*for (int i = 0; i < n; i++) {
		scanf("%d", arr[i]);
	}
	int key = 0; // 현재 넣을 숫자 
	int tail = 0;
	for (int i = 0; i < n; i++) {
		if (key <= arr[i]) { // 현재 들어간 숫자보다 클경우만 push실행 
			for (int j = 0; j < arr[i] - key; j++) { //push할 숫자 -현재 들어간 최대 숫자 의 차 만큼만 push함
				arr2[tail++] = key;
			}
			
		}
	}*/
}
