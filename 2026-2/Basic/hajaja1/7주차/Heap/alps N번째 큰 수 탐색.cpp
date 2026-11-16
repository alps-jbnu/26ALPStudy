#include <bits/stdc++.h>
using namespace std;

int main() {

	priority_queue<int> max_heap;
	priority_queue<int, vector<int>, greater<int>> min_heap;

	int n = 0, input = 0, tmp1 = 0, tmp2 = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> input;
			if (min_heap.size() < n) { min_heap.push(input); } // 힙의 원소의 개수가 n개가 될때 까지 밀어 넣음
			else {
				if (input > min_heap.top()) { // 원소의 개수가 n개이면 입력의 값과 크기를 비교하여 큰값이면 원소를 삭제하고 새로 입력함
					min_heap.pop();
					min_heap.push(input);
				}
			}
		}
	}
	cout << min_heap.top() << '\n';
	return 0;
}
