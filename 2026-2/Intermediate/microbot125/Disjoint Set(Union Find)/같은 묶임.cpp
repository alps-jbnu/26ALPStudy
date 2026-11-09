//
// Created by 손민균 on 26. 10. 16.
//
#include <iostream>
#include <vector>
using namespace std;

class Total_Set {
    public:
    vector<int> element;
    Total_Set(int n) {
        element = vector<int>(n + 1, -1);
    }
    int find(int n) {
        if (element[n] == -1) return n;
        else return element[n] = find(element[n]);
    }
    bool uni(int a, int b) {
        int a_group = find(a);
        int b_group = find(b);
        if (a_group == b_group) return true;
        if (element[a_group] < element[b_group]) element[b_group] = a_group;
        else element[a_group] = b_group;
        return false;
    }
    bool same_group(int a, int b) {
        return find(a) == find(b);
    }
};


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    Total_Set ts(n);
    for (int i = 0; i < m; i++) {
        int input, a, b;
        cin >> input >> a >> b;
        if (input == 0) ts.uni(a, b);
        else cout << (ts.same_group(a, b)?"YES":"NO") << endl;
    }
    return 0;
}