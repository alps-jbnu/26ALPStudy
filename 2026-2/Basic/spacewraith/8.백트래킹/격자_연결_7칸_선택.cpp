#include <iostream>
#include <vector>

using namespace std;

string grid[5];
bool is_selected[5][5];
int cnt;

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

void find_cells(int length, int S_cnt, int bound) {
	if(length == 7) {
		if(S_cnt >= 4) {
			cnt++;		
		}

		return;
	}

	for(int i = bound; i < 25; i++) {
		int cr = i / 5;
		int cc = i % 5;

		bool is_vaild = false;
		for(int j = 0; j < 4; j++) {
			int nr = cr + dr[j];
			int nc = cc + dc[j];

			if(nr < 0 || nr >= 5 || nc < 0 || nc >= 5) continue;
			if(!is_selected[nr][nc]) continue;

			is_vaild = true;
		}

		if(length == 0) is_vaild = true;

		if(!is_vaild) continue;

		if(grid[cr][cc] == 'S') S_cnt++;
		is_selected[cr][cc] = true;

		find_cells(length + 1, S_cnt, i + 1);

		if(grid[cr][cc] == 'S') S_cnt--;
		is_selected[cr][cc] = false;

	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	for(int i = 0; i < 5; i++) {
		cin >> grid[i];
	}


	find_cells(0, 0, 0);

	cout << cnt << '\n';

	return 0;
}

