//
// Created by 손민균 on 26. 10. 13.
//
#include <iostream>
class TREE;
using namespace std;

class NODE {
    public:
    TREE* tree;
    NODE* parent;
    NODE* left;
    NODE* right;
    int value;
    NODE(int val, TREE* t) {
        parent = nullptr;
        left = nullptr;
        right = nullptr;
        value = val;
        tree = t;
    }
    ~NODE() {
        delete left;
        delete right;
    }
    NODE* insert(int val) {
        if (value <= val) {
            if (right == nullptr) {
                right = new NODE(val, tree);
                right -> parent = this;
                return right;
            }
            else return (right -> insert(val));
        }
        else {
            if (parent == nullptr) {
                parent = new NODE(val, tree);
                parent -> left = this;
                return parent;
            }
            else if (parent -> value <= val) {
                NODE* parent_backup = parent;
                parent = new NODE(val, tree);
                parent -> parent = parent_backup;
                parent -> parent -> right = parent;
                parent -> left = this;
                return parent;
            }
            else {
                return (parent -> insert(val));
            }
        }
    }
    pair<long long, long long> score() const {
        pair<long long, long long> left_result = {0, 0}, right_result = {0, 0};
        if (left != nullptr) {
            left_result = left -> score();
        }
        if (right != nullptr) {
            right_result = right -> score();
        }
        long long interval_sum = left_result.first + right_result.first + value;
        long long interval_score = interval_sum * value;
        if (interval_score < left_result.second) interval_score = left_result.second;
        if (interval_score < right_result.second) interval_score = right_result.second;
        return {interval_sum, interval_score};
    }
};

class TREE {
    public:
    NODE* root;
    NODE* current;
    TREE() {
        root = nullptr;
        current = nullptr;
    }
    ~TREE() {
        delete root;
    }
    void insert(int n) {
        if (root == nullptr) {
            root = new NODE(n, this);
            current = root;
        }
        else {
            current = current -> insert(n);
            if (current -> left == root) root = current;
        }
    }
    long long score() const {
        return (root -> score()).second;
    }
};

int main () {
    TREE tree;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        tree.insert(val);
    }

    cout << tree.score() << endl;
    return 0;
}