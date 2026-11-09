#include <iostream>
#include <vector>

using namespace std;

int combination[6];
int length = 0;

void find_combination(vector<int> &nums, int bound) {
	if(length == 6) {
		for(int c : combination){
			cout << c << ' ';
		}

		cout << '\n';
		
		return;
	}

	for(int i = bound; i < nums.size(); i++) {
		combination[length++] = nums[i];
		find_combination(nums, i + 1);
		length--;
	}

}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	while(true) {
		int k;
		cin >> k;

		if(k == 0) break;

		vector<int> nums(k);

		for(int &c : nums) {
			cin >> c;
		}

		find_combination(nums, 0);
		cout << '\n';
	}

	return 0;
}
