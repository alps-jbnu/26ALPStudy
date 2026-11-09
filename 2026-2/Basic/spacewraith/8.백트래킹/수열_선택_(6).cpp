#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> seq;

void find_seq(const vector<int> &nums, int n, int m, int bound) {
	if(seq.size() == m) {
		for(int i : seq) {
			cout << i << ' ';
		}
		
		cout << '\n';

		return;
	}

	for(int i = bound; i < n; i++) {
		seq.push_back(nums[i]);
		find_seq(nums, n, m, i + 1);
		seq.pop_back();
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;

	cin >> n >> m;

	vector<int> nums(n);
	for(int &i : nums) {
		cin >> i;
	}

	sort(nums.begin(), nums.end());

	find_seq(nums, n, m, 0);

	return 0;
}

