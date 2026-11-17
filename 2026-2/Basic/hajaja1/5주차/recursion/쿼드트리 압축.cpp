#include <bits/stdc++.h>
using namespace std;
vector<char> que; //출력을 저장할 큐의 역할
char arr[64][64]; //최대 64by64인 행렬

void quadra(int N, int a, int b) { // 행렬의 한변의 길이 N과 시작 좌표 a,b
	
	if (N == 1) {
		switch(arr[a][b]) { // 행열의 길이가 1이면 요소의 값을 큐에 바로 넣음
        case  0: que.push_back(0);  return;
        case  1: que.push_back(1);  return;
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
		que.push_back(arr[a][b]);
	}
	else {
		que.push_back('(');
		int n4 = N / 2;
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				quadra(n4, a + n4 * i, b + n4 * j);
			}
		}
		que.push_back(')');
	}
	return;
}

int main() {
	int N = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	/*for (int i = 0; i < N; i++) {
		cout << arr[i] <<'\n';
	}*/
	quadra(N, 0, 0);
	for (char o : que) {
		cout << o;
	}
	return 0;
}