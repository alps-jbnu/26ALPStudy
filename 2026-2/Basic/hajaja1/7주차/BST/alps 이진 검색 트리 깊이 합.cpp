#include <iostream>
#include <set>
#include <map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (!(cin >> N)) return 0;

    set<int> s;
    map<int, int> depth; // 각 노드의 깊이 저장
    long long total_depth_sum = 0;

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;

        if (i == 0) {
            s.insert(x);
            depth[x] = 0; // 루트의 깊이는 0 (문제에 따라 1부터 시작할 수도 있으니 누적 관리)
        }
        else {
            auto it = s.upper_bound(x);
            int d = 0;

            if (it == s.end()) {
                // 자신보다 큰 값이 없다면, 가장 큰 값(왼쪽 또는 오른쪽)의 바로 아래
                auto prev_it = prev(it);
                d = depth[*prev_it] + 1;
            }
            else if (it == s.begin()) {
                // 자신보다 작은 값이 없다면
                d = depth[*it] + 1;
            }
            else {
                auto prev_it = prev(it);
                // 양쪽 값 중 깊이가 더 큰 쪽의 자식으로 들어감
                d = max(depth[*prev_it], depth[*it]) + 1;
            }

            depth[x] = d;
            s.insert(x);
        }
        total_depth_sum += depth[x];
    }

    // 문제에서 루트 깊이를 1로 계산하라고 했으므로,
    // 루트 깊이를 0으로 계산했다면 전체 합에 N을 더해줍니다.
    // (루트 포함 총 N개의 노드가 각각 깊이 1씩 증가하므로 +N)
    cout << total_depth_sum + N << "\n";

    return 0;
}