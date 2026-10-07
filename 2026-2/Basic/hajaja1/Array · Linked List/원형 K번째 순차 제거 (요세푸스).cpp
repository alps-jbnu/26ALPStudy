#include <stdio.h>
int erase(int arr[], int k, int len) { //k번째 원소 삭제
	int e = arr[k];
	for (int i = k; i < len-1; i++) {
		arr[i] = arr[i + 1]; //k가 0일경우 arr[0]의 값을 arr[1]의 값으로 바꿈, 이떄 길이가 1이었다면 arr[1]의 값은 \0임
	}
	return e;
}
int main() {
	int N = 0;
	int K = 0;
	scanf("%d %d", &N, &K); // N, K입력 받기
	int yo[5000] = {}; // 순서 배열 최대 5000까지 5001인 이유는 마지막에\0이 저장되어야 함
	for (int i = 0; i < N; i++) {
		yo[i] = i + 1; //각 자리 숫자 1,2,3...순서대로 입력
	}
	int len = N;
	int cur = 0;
	int idx[5000] = {}; //지워진 순서 저장 배열
	for (int j = 0; j < N; j++) {
		cur = (cur + K - 1) % len; // 배열의 길이 보다 길면 len으로 나눠서 순서를 맞춤
		idx[j] = erase(yo, cur, len);
		len--;
	}
	printf("<");
	for (int o = 0; o < N-1; o++) {
		printf("%d, ", idx[o]);
	}
	printf("%d", idx[N-1]);
	printf(">");
	return 0;
}