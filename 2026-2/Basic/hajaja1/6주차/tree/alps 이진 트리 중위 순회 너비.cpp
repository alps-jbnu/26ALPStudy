#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
    int left;
    int right;
};

int N;
vector<Node> tree;
vector<int> parent;
vector<int> min_col;
vector<int> max_col;

int col_idx = 1;
int max_depth = 0;

void inorder(int curr, int depth) {
    if (curr == -1) return;

    max_depth = max(max_depth, depth);

    // 1. 왼쪽 자식 순회
    inorder(tree[curr].left, depth + 1);

    // 2. 현재 노드 처리 (열 번호 기록 및 레벨별 min/max 갱신)
    if (min_col[depth] == 0 || col_idx < min_col[depth]) {
        min_col[depth] = col_idx;
    }
    if (col_idx > max_col[depth]) {
        max_col[depth] = col_idx;
    }
    col_idx++;

    // 3. 오른쪽 자식 순회
    inorder(tree[curr].right, depth + 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    tree.resize(N + 1);
    parent.assign(N + 1, 0);
    min_col.assign(N + 1, 0);
    max_col.assign(N + 1, 0);

    for (int i = 0; i < N; i++) {
        int node, l, r;
        cin >> node >> l >> r;
        tree[node].left = l;
        tree[node].right = r;

        if (l != -1) parent[l] = node;
        if (r != -1) parent[r] = node;
    }

    // 부모가 없는 노드가 루트 노드
    int root = 1;
    for (int i = 1; i <= N; i++) {
        if (parent[i] == 0) {
            root = i;
            break;
        }
    }

    // 중위 순회 실행 (루트 레벨 = 1)
    inorder(root, 1);

    int ans_level = 1;
    int max_width = 0;

    for (int d = 1; d <= max_depth; d++) {
        int width = max_col[d] - min_col[d] + 1;
        if (width > max_width) {
            max_width = width;
            ans_level = d;
        }
    }

    cout << ans_level << " " << max_width << "\n";

    return 0;
}
