#include <bits/stdc++.h>
using namespace std;

int main() {

	priority_queue<int> max_heap;
	priority_queue<int, vector<int>, greater<int>> min_heap;

	int n = 0, input = 0, tmp1 =0, tmp2 = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> input;
		if (max_heap.size() == min_heap.size()) { // 최대힙의 크기와 최소힙의 크기가 같으면 최대힙에 값을 넣는다
			max_heap.push(input);
		}
		else { // 다르면 최소힙에 넣는다
			min_heap.push(input);
		}
		if (i != 0) {
			if (max_heap.top() > min_heap.top()) { // 값을 넣은 후에 최대힙과 최소힙의 루트의 값을 비교하여 만약 최대힙의 루트값이 최소힙의 루트값보다 크면 둘의 값을 바꾼다.
				tmp1 = max_heap.top();
				tmp2 = min_heap.top();
				max_heap.pop();
				min_heap.pop();
				max_heap.push(tmp2);
				min_heap.push(tmp1);
			}
		}
		cout << max_heap.top() << '\n';
	}
	return 0;
}