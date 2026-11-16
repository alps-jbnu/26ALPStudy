#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	
	int T = 0, K = 0, input = 0;
	
	cin >> T;
	for (int i = 0; i < T; i++) {
		priority_queue<long long, vector<long long>, greater<long long>> min_heap;
		long long minsum = 0, sum = 0;
		cin >> K;
		for (int j = 0; j < K; j++) {
			cin >> input;
			min_heap.push(input);
		}
		
		for (int j = 1; j < K; j++) {
			minsum = min_heap.top();
			min_heap.pop();
			minsum += min_heap.top();
			min_heap.pop();
			min_heap.push(minsum);
			sum += minsum;
		}
		cout << sum << '\n';
	}
	return 0;
}
