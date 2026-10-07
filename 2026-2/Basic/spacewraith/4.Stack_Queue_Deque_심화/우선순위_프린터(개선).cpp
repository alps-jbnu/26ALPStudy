//pair 자료구조를 사용해서 인덱스 관리를 더욱 단순하게 했다

#include <iostream>
#include <queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T = 0;
	
	cin >> T;

	while(T--) {
		int N, M;
		int highest_prior = 0;
		int print_count = 0;
		int count[10] = {0, };
		queue<pair<int, int>> q;

		cin >> N >> M;

		for(int i = 0; i < N; i++) {
			int input;

			cin >> input;
			q.push({input, i});
			count[input]++;

			if(highest_prior < input) 
				highest_prior = input;
		}

		while(!q.empty()) {
			auto [cur_p, cur_idx] = q.front();
			if(cur_p == highest_prior) {
				print_count++;
				count[cur_p]--;

				if(cur_idx == M) {
					cout << print_count << '\n';
					break;
				} 

				if(count[cur_p] == 0) {			
					for(int i = cur_p - 1; i > 0; i--)	{
						if(count[i] != 0) {
							highest_prior = i;
							break;
						}
					}
				}

				q.pop();
			} else {
				q.push(q.front());
				q.pop();
			}
		}

	
	}

	return 0;
}
