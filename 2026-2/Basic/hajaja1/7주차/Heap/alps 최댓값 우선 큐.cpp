#include <bits/stdc++.h>

using namespace std;

int main() {

	priority_queue<int> max_heap;
	int n = 0, input = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> input;
		if (input == 0) {
			if (max_heap.size() == 0) {
				cout << "0\n"; // 만약 최대힙에 원소가 없다면 0출력
			}
			else { // 최대값을 반환하고 삭제
				cout << max_heap.top() << '\n';
				max_heap.pop();
			}
		}
		else if (input > 0) { // 입력이 양수이면 최대힙에 추가
			max_heap.push(input);
		}
	}
	return 0;
}
