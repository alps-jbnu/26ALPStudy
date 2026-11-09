#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> seq;
bool used[10];

void find_seq(const vector<int> &nums, int n, int m) {
	if(seq.size() == m) {
		for(int i : seq) {
			cout << i << ' ';
		}
		
		cout << '\n';

		return;
	}

	for(int i = 0; i < n; i++) {
		if(!used[i]) {
			seq.push_back(nums[i]);
			used[i] = true;

			find_seq(nums, n, m);

			seq.pop_back();
			used[i] = false;

			while(i + 1 < n && nums[i] == nums[i + 1])
				i++;
		}	

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

	find_seq(nums, n, m);

	return 0;
}

