#include <bits/stdc++.h>
using namespace std;

int main() {
	queue<int> quu;
	int N = 0;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		quu.push(i); //큐에 순서대로 넣음
	}
	for (int j = 0; j < N-1; j++) {
		quu.pop(); //젤처음꺼 없애기
		quu.push(quu.front()); //그 다음꺼 주입
		quu.pop(); //없앰
	}
	printf("%d", quu.front());
	return 0;
}