#include <iostream>
#include <vector>

using namespace std;

int N, R, Q;
vector<vector<int>> adj;
vector<int> subtree_size;

// DFS를 통해 각 노드의 서브트리 크기 계산
int count_subtrees(int curr, int parent) {
    subtree_size[curr] = 1; // 자기 자신 포함

    for (int next : adj[curr]) {
        if (next != parent) { // 부모 방향으로 역류 방지
            subtree_size[curr] += count_subtrees(next, curr);
        }
    }

    return subtree_size[curr];
}

int main() {
    // 입출력 속도 향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> R >> Q;

    adj.resize(N + 1);
    subtree_size.resize(N + 1, 0);

    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // 루트 R부터 DFS를 수행하여 모든 노드의 서브트리 크기 계산
    count_subtrees(R, 0);

    // Q개의 쿼리 처리
    for (int i = 0; i < Q; i++) {
        int query_node;
        cin >> query_node;
        cout << subtree_size[query_node] << "\n";
    }

    return 0;
}