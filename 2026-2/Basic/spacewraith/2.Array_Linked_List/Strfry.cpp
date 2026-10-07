#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	while(N) {
		string a, b;
		vector<int> count_a(26, 0);
		vector<int> count_b(26, 0);

		cin >> a >> b;

		if(a.length() != b.length()) {
			cout << "Impossible" << '\n';
			N--;
			continue;
		}

		for(int i = 0; i < a.length(); i++) {
			count_a[a[i] - 'a']++;
			count_b[b[i] - 'a']++;
		}

		if(count_a == count_b) {
			cout << "Possible" << '\n';
		} else {
			cout << "Impossible" << '\n';
		}

		N--;
	}
}
