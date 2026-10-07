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
		queue<int> q;

		cin >> N >> M;

		for(int i = 0; i < N; i++) {
			int input;

			cin >> input;
			q.push(input);
			count[input]++;

			if(highest_prior < input) 
				highest_prior = input;
		}

		while(!q.empty()) {
			if(q.front() == highest_prior) {
				print_count++;
				count[q.front()]--;

				if(M == 0) {
					cout << print_count << '\n';
					break;
				} else {
					M--;
				}

				if(count[q.front()] == 0) {			
					for(int i = q.front() - 1; i > 0; i--)	{
						if(count[i] != 0) {
							highest_prior = i;
							break;
						}
					}
				}

				q.pop();
			} else {
				if(M == 0) {
					M = q.size() - 1;
				} else {
					M--;
				}

				q.push(q.front());
				q.pop();
			}
		}

	
	}

	return 0;
}
