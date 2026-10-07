#include <iostream>
#include <deque>
#include <numeric>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N = 0, M = 0;
	int result = 0;
	
	cin >> N >> M;

	deque<int> dq(N);
	iota(dq.begin(), dq.end(), 1);

	while(M--) {
		int target = 0;
		int idx = 0;

		cin >> target;
		for(int i = 0; i < dq.size(); i++) {
			if(dq[i] == target){
				idx = i;
				break;
			}
		}

		if(idx <= dq.size() - idx) {
			while(dq.front() != target){
				dq.push_back(dq.front());
				dq.pop_front();
				result++;
			}
		} else {
			while(dq.front() != target) {
				dq.push_front(dq.back());
				dq.pop_back();
				result++;
			}
		}

		dq.pop_front();
	}

	cout << result;
}
