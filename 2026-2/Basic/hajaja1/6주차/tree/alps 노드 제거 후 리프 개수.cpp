#include <iostream>
#include <vector>

using namespace std;

int n;
vector<vector<int>> tree;
int remove_node;
int root_node;
int leaf_count = 0;

void dfs(int current) {
    int valid_children = 0;

    for (int child : tree[current]) {
        // 삭제할 노드는 탐색하지 않음
        if (child == remove_node) continue;

        valid_children++;
        dfs(child);
    }

    // 유효한 자식이 하나도 없으면 리프 노드임
    if (valid_children == 0) {
        leaf_count++;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    tree.resize(n);

    for (int i = 0; i < n; i++) {
        int parent;
        cin >> parent;
        if (parent == -1) {
            root_node = i;
        }
        else {
            tree[parent].push_back(i);
        }
    }

    cin >> remove_node;

    // 루트 노드가 삭제되는 예외 처리
    if (remove_node == root_node) {
        cout << 0 << "\n";
        return 0;
    }

    dfs(root_node);

    cout << leaf_count << "\n";

    return 0;
}