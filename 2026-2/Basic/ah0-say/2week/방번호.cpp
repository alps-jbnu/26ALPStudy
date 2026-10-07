#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	int n;
	cin >> n;

	int cnt[10] = {};
	while (n > 0) {
		cnt[n % 10]++;
		n /= 10;
	}

	int ans = 0;
	for (int i = 0; i < 10; i++) {
		if (i == 6 || i == 9) continue;
		ans = max(ans, cnt[i]);
	}
	ans = max(ans, (cnt[6] + cnt[9] + 1) / 2);

	cout << ans;
}
