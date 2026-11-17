#include <iostream>
#include <vector>

using namespace std;

void func(vector<vector<char>> &board, int r, int c, int size) {

	if(size == 3) {
		for(int i = r; i < r + size; i++) {
			for(int j = c; j < c + size; j++) {
				if(i == r + 1 && j == c + 1)
					continue;

				board[i][j] = '*';
			}
		}

		return;
	}

	int third = size / 3;
	for(int dr = 0; dr < 3; dr++) {
		for(int dc = 0; dc < 3; dc++) {
			if(dr == 1 && dc == 1)
				continue;
			func(board, r + dr * third, c + dc * third, third);
		}

	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;

	cin >> N;

	vector<vector<char>> board(N, vector<char>(N, ' '));

	func(board, 0, 0, N);

	for(vector<char> row : board) {
		for(char c : row) {
			cout << c;
		}

		cout << '\n';
	}

	return 0;
}

