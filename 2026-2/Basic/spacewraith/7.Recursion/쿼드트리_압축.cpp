#include <iostream>
#include <string>
#include <vector>

using namespace std;

void func(vector<string> &grid, int r, int c, int size) {
	if(size == 0) return;

	bool is_uniform = true;
	char target = grid[r][c];
	for(int i = r; i < r + size; i++) {
		for(int j = c; j < c + size; j++) {
			if(target != grid[i][j]) {
				is_uniform = false;
				break;
			}
		}

		if(!is_uniform) break;
	}

	if(is_uniform) {
		cout << target;
		return;
	}

	int half = size / 2;
	cout << '(';
	for(int dr = 0; dr < 2; dr++){
		for(int dc = 0; dc < 2; dc++) {
			func(grid, r + half * dr, c + half * dc, half);
		}
	}
	cout << ')';

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;

	cin >> N;

	vector<string> grid(N);

	for(string &s : grid) {
		cin >> s;
	}


	func(grid, 0, 0, N);


	return 0;
}

