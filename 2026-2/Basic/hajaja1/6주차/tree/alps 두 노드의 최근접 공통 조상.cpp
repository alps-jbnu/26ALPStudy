#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int N;
    cin >> N;

    vector<int> parent(N + 1, 0);
    vector<bool> visited(N + 1, false);

    // N-1개의 부모-자식 관계 입력
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        parent[v] = u; // u가 v의 부모
    }

    int nodeA, nodeB;
    cin >> nodeA >> nodeB;

    // nodeA에서 시작하여 루트까지 올라가며 방문 체크
    int curr = nodeA;
    while (curr != 0) {
        visited[curr] = true;
        curr = parent[curr];
    }

    // nodeB에서 시작하여 루트로 올라가다가 처음 방문했던 노드를 만나면 그 노드가 LCA
    curr = nodeB;
    while (curr != 0) {
        if (visited[curr]) {
            cout << curr << "\n";
            return;
        }
        curr = parent[curr];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}