#include <bits/stdc++.h>

using namespace std;

int main() {

	priority_queue<int, vector<int>, greater<int>> min_heap;
	int n = 0, input = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> input;
		if (input == 0) {
			if (min_heap.size() == 0) {
				cout << "0\n"; // 만약 최소힙에 원소가 없다면 0출력
			}
			else { // 최소값을 반환하고 삭제
				cout << min_heap.top() << '\n';
				min_heap.pop();
			}
		}
		else if (input > 0) { // 입력이 양수이면 최소힙에 추가
			min_heap.push(input);
		}
	}
	return 0;
}