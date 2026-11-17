#include <iostream>
#include <vector>

using namespace std;

int cnt[3];

void func(vector<vector<int>> &grid, int r, int c, int size){
	if(size == 0) {
		return;
	}

	int first = grid[r][c];
	bool flag = true;
	for(int i = r; i < r + size; i++) {
		for(int j = c + 1; j < c + size; j++) {
			if(grid[i][j] != first)	{
				flag = false;
				break;
			}
		}

		if(!flag) break;
	}

	if(flag) {
		cnt[first + 1]++;
		return;
	}

	int third = size / 3;

	for(int dr = 0; dr < 3; dr++){
		for(int dc = 0; dc < 3; dc++) {
			func(grid, r + dr * third, c + dc * third, third);
		}
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;

	cin >> N;

	vector<vector<int>> grid(N, vector<int>(N));

	for(vector<int> &row : grid) {
		for(int &i : row) {
			cin >> i;
		}
	}


	func(grid, 0, 0, N);

	for(int i : cnt) {
		cout << i << '\n';
	}


	return 0;
}
