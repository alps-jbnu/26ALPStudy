//
// Created by 손민균 on 26. 10. 13.
//
#include <iostream>
#include <vector>
using namespace std;

int divide_and_conquer(vector<vector<int> >& paper, int length, int start_x, int start_y, int& minus_paper, int& plus_paper, int& zero_paper) {
    if (length == 1) return paper[start_y][start_x];
    vector< vector<int> > mini_paper(3, vector<int>(3, 0));
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            mini_paper[j][i] = divide_and_conquer(paper, length / 3, start_x + i * length / 3, start_y + j * length / 3, minus_paper, plus_paper, zero_paper);
        }
    }
    int criteria = mini_paper[0][0];
    bool same_flag = true;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (mini_paper[i][j] != criteria) same_flag = false;
        }
    }
    if (same_flag) return criteria;
    else {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (mini_paper[i][j] == 1) plus_paper++;
                else if (mini_paper[i][j] == 0) zero_paper++;
                else if (mini_paper[i][j] == -1) minus_paper++;
            }
        }
        return -2;
    }
}

int main() {
    int n;
    cin >> n;
    vector< vector<int> > paper(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> paper[i][j];
        }
    }
    int minus_paper = 0;
    int plus_paper = 0;
    int zero_paper = 0;
    int last_paper = divide_and_conquer(paper, n, 0, 0, minus_paper, plus_paper, zero_paper);
    if (last_paper == -1) minus_paper++;
    else if (last_paper == 0) zero_paper++;
    else if (last_paper == 1) plus_paper++;
    cout << minus_paper << endl;
    cout << zero_paper << endl;
    cout << plus_paper << endl;
    return 0;
}