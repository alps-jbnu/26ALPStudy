#include <bits/stdc++.h>
using namespace std;

int main() {
	
	int N = 0, M =0;
	cin >> N >> M;
	int siz = N;
	int dequu[50] = {};
	//cout << N << M;
	for (int i = 1; i <= siz; i++) {
		dequu[i] = i; // 큐에 순차적으로 대입
	}
	int k = 0;
	int cur = 1;
	int min = 0;
	int co = 0;
	int s = 0;
	for (int j = 0; j < M; j++) {
		cin >> k;
		for (int p = 1; p <= siz; p++) {
			if (k == dequu[p]) {
				co = p; break;
			}
		}
		if (cur < co) {
			int d1 = co - cur;
			int d2 = (siz - co + 1) + (cur - 1);
			min = d1 > d2 ? d2 : d1;
			//cout << min << "\ncur < co\n" << cur << " " << co << "\n";
			s += min;
			cur = co;
			for (int o = cur; o <= siz-1; o++) {
				dequu[o] = dequu[o + 1];
			}
			siz--;
		}
		else if (cur > co) {
			int d1 = cur - co;
			int d2 = (siz - cur + 1) + (co - 1);
			min = d1 > d2 ? d2 : d1;
			//cout << min << "\ncur > co\n"<< cur<<" "<<co<<"\n";
			s += min;
			cur = co;
			for (int o = cur; o <= siz - 1; o++) {
				dequu[o] = dequu[o + 1];
			}
			siz--;
		}
		else {
			for (int o = cur; o <= siz - 1; o++) {
				dequu[o] = dequu[o + 1];
			}
			//cout << "\ncur < co\n" << cur << " " << co << "\n";
			siz--;
		}
	}
	cout << s;
	return 0;
}