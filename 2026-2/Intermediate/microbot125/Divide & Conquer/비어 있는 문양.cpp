//
// Created by 손민균 on 26. 10. 14.
//
#include <iostream>
#include <vector>
using namespace std;

void draw_star(vector< vector<char> > & paper, int start_x, int start_y, int width) {
    if (width == 3) {
        for (int i = start_x; i < start_x + width; i++) {
            for (int j = start_y; j < start_y + width; j++) {
                if (i != start_x + 1 || j != start_y + 1) paper[i][j] = '*';
            }
        }
    }
    else {
        for (int i = start_x; i < start_x + width; i += width / 3) {
            for (int j = start_y; j < start_y + width; j += width / 3) {
                if (i != start_x + width / 3 || j != start_y + width / 3) draw_star(paper, i, j, width / 3);
            }
        }
    }
}

int main() {
    int n;
    cin >> n;

    vector< vector<char> > paper(n, vector<char>(n));
    draw_star(paper, 0, 0, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (paper[i][j] == '*') cout << '*';
            else cout << ' ';
        }
        cout << endl;
    }
    return 0;
}