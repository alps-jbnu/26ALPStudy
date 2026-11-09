//
// Created by 손민균 on 26. 10. 16.
//
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//크루스칼 기준으로 사실상 유니온 파인드 문제나 다름이 없으나 일단 학습을 위해서 주석으로 그래프 만드는 코드 추가한 상태입니다.

class Total_Set {
public:
    vector<int> element;
    Total_Set(int n) {
        element = vector<int>(n, -1);
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

bool compare(const pair<pair<int, int>, int> &a, const pair<pair<int, int>, int> &b) {
    return a.second < b.second;
}

int main() {
    int n, m;
    cin >> n >> m;
    //vector<vector<int> > graph(n, vector<int>(n, -1));
    //vector<vector<int> > graph2(n, vector<int>(n, -1));
    Total_Set Disjoint(n);

    vector<pair<pair<int, int>, int> > E;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        //if (graph[a - 1][b - 1] == -1 || graph[a - 1][b - 1] > c) graph[a - 1][b - 1] = c;
        E.emplace_back(make_pair(a - 1, b - 1), c);
    }

    sort(E.begin(), E.end(), compare);
    int select = 0;
    int total = 0;
    for (auto & i : E) {
        if (select == n - 2) break;
        bool same = Disjoint.uni(i.first.first, i.first.second);
        if (!same) {
            select++;
            total += i.second;
            //graph2[i.first.first][i.first.second] = i.second;
        }
    }

    cout << total << endl;

    return 0;
}