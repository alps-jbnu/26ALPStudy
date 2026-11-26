#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    // 입출력 속도 향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, Q;
    if (!(cin >> N >> Q)) return 0;

    vector<int> state(N);
    set<int> active_set;

    for (int i = 0; i < N; i++) {
        cin >> state[i];
        if (state[i] == 1) {
            active_set.insert(i);
        }
    }

    int curr = 0; // 현재 위치 (0부터 N-1)

    for (int q = 0; q < Q; q++) {
        int type;
        cin >> type;

        if (type == 1) {
            int i;
            cin >> i;
            // 문제에서 구역 번호가 1부터 주어지는지 0부터 주어지는지에 따라 조정
            // 여기서는 1-based index라고 가정하고 i-1로 변환 (0-based라면 i 그대로 사용)
            // 일반적으로 백준/알고리즘 문제의 인덱스를 고려하여 1-based라 가정하면:
            int idx = i - 1;

            if (state[idx] == 1) {
                state[idx] = 0;
                active_set.erase(idx);
            }
            else {
                state[idx] = 1;
                active_set.insert(idx);
            }
        }
        else if (type == 2) {
            long long x;
            cin >> x;
            curr = (curr + (x % N)) % N;
        }
        else if (type == 3) {
            if (active_set.empty()) {
                cout << -1 << "\n";
            }
            else {
                auto it = active_set.lower_bound(curr);
                int next_pos;
                if (it != active_set.end()) {
                    next_pos = *it;
                }
                else {
                    // 현재 위치 이상에 활성 구역이 없으면 원형 구조에 의해 가장 작은 번호의 활성 구역 선택
                    next_pos = *active_set.begin();
                }

                int dist = 0;
                if (next_pos >= curr) {
                    dist = next_pos - curr;
                }
                else {
                    dist = (N - curr) + next_pos;
                }
                cout << dist << "\n";
            }
        }
    }

    return 0;
}