#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int left;
    int right;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<Node> tree(N + 1);
    for (int i = 0; i < N; i++) {
        int node, left, right;
        cin >> node >> left >> right;
        tree[node] = { left, right };
    }

    // 루트에서 출발하여 오른쪽 자식만 계속 따라갔을 때의 우측 끝 경로 길이 구하기
    int right_spine_length = 0;
    int curr = 1;
    while (true) {
        if (tree[curr].right != -1) {
            right_spine_length++;
            curr = tree[curr].right;
        }
        else {
            break;
        }
    }

    // 총 이동 횟수 = (N - 1) * 2 - (오른쪽 끝 경로 길이)
    int total_moves = (N - 1) * 2 - right_spine_length;

    cout << total_moves << "\n";

    return 0;
}