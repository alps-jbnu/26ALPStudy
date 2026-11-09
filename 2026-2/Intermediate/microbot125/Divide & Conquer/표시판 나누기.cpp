//
// Created by 손민균 on 26. 10. 13.
//
#include <iostream>
#include <algorithm>
#include <vector>
#define HORIZONTAL 0
#define VERTICAL 1
using namespace std;

long long save_state[21][21][21][21][2];

pair<int, int> get_number_of_1_and_2_in_area(vector< vector< pair<int, int> > > const & plate, int start_x, int start_y, int end_x, int end_y) {
    int one_num = plate[end_y][end_x].first - plate[start_y - 1][end_x].first - plate[end_y][start_x - 1].first + plate[start_y - 1][start_x - 1].first;
    int two_num = plate[end_y][end_x].second - plate[start_y - 1][end_x].second - plate[end_y][start_x - 1].second + plate[start_y - 1][start_x - 1].second;
    return {one_num, two_num};
}

long long divide (vector< vector< pair<int, int> > > & plate, int start_x, int start_y, int end_x, int end_y, int direction) {
    long long result = 0;
    pair<int, int> one_and_two_num = get_number_of_1_and_2_in_area(plate, start_x, start_y, end_x, end_y);
    if (one_and_two_num.first == 0 && one_and_two_num.second == 1) return 1;
    else if (one_and_two_num.first == 0 && one_and_two_num.second != 1) return 0;
    else if (one_and_two_num.first > 0 && one_and_two_num.second == 0) return 0;
    else if (direction == HORIZONTAL) {
        for (int i = start_y + 1; i < end_y; i++) {
            pair<int, int> line_one_and_two_num = get_number_of_1_and_2_in_area(plate, start_x, i, end_x, i);
            if (line_one_and_two_num.second == 0 && line_one_and_two_num.first > 0) {
                if (save_state[start_y][start_x][i - 1][end_x][VERTICAL] == -1) {
                    save_state[start_y][start_x][i - 1][end_x][VERTICAL] = divide(plate, start_x, start_y, end_x, i - 1, VERTICAL);
                }
                if (save_state[i + 1][start_x][end_y][end_x][VERTICAL] == -1) {
                    save_state[i + 1][start_x][end_y][end_x][VERTICAL] =  divide(plate, start_x, i + 1, end_x, end_y, VERTICAL);
                }
                long long up_tetragon = save_state[start_y][start_x][i - 1][end_x][VERTICAL];
                long long down_tetragon = save_state[i + 1][start_x][end_y][end_x][VERTICAL];
                result += up_tetragon * down_tetragon;
            }
        }
    }
    else {
        for (int i = start_x + 1; i < end_x; i++) {
            pair<int, int> line_one_and_two_num = get_number_of_1_and_2_in_area(plate, i, start_y, i, end_y);
            if (line_one_and_two_num.second == 0 && line_one_and_two_num.first > 0) {
                if (save_state[start_y][start_x][end_y][i - 1][HORIZONTAL] == -1) {
                    save_state[start_y][start_x][end_y][i - 1][HORIZONTAL] = divide(plate, start_x, start_y, i - 1, end_y, HORIZONTAL);
                }
                if (save_state[start_y][i + 1][end_y][end_x][HORIZONTAL] == -1) {
                    save_state[start_y][i + 1][end_y][end_x][HORIZONTAL] =  divide(plate, i + 1, start_y, end_x, end_y, HORIZONTAL);
                }
                long long left_tetragon = save_state[start_y][start_x][end_y][i - 1][HORIZONTAL];
                long long right_tetragon = save_state[start_y][i + 1][end_y][end_x][HORIZONTAL];
                result += left_tetragon * right_tetragon;
            }
        }
    }
    return result;
}

int main () {
    fill(&save_state[0][0][0][0][0], (&save_state[20][20][20][20][1] + 1), -1);
    int n;
    cin >> n;
    //예외 처리의 단순함을 위하여 위쪽/왼쪽 테두리 추가
    vector< vector< pair<int, int> > > plate(n + 1, vector<pair<int, int> >(n + 1, {0, 0}));
    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < n + 1; j++) {
            int temp;
            cin >> temp;
            if (temp == 1) {
                plate[i][j].first = 1;
            }
            if (temp == 2) {
                plate[i][j].second = 1;
            }
        }
    }

    //누적합 행렬로 개편, 구역의 시작점과 끝점에서의 값을 입력으로 구역내 1과 0의 개수를 O(1)으로 접근
    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < n + 1; j++) {
            plate[i][j].first += plate[i - 1][j].first + plate[i][j - 1].first - plate[i - 1][j - 1].first;
            plate[i][j].second += plate[i][j - 1].second + plate[i - 1][j].second - plate[i - 1][j - 1].second;
        }
    }

    //쪼갤 필요가 없는 판에 대한 예외처리
    if (get_number_of_1_and_2_in_area(plate, 1, 1, n, n).first == 0 &&
        get_number_of_1_and_2_in_area(plate, 1, 1, n, n).second == 1) cout << 1 << endl;
    //쪼개기
    else {
        long long horizonal = divide(plate, 1, 1, n, n, HORIZONTAL);
        long long vertical = divide(plate, 1, 1, n, n, VERTICAL);
        if (horizonal + vertical == 0) cout << -1 << endl;
        else cout << horizonal + vertical << endl;
    }

    return 0;
}

/*
pair<int, int> divide(vector< vector<int> >& plate, int start_x, int start_y, int end_x, int end_y, int direction) {
    int one_num = 0;
    int two_num = 0;
    pair<int, int> result = {0, 0};
    if (direction == HORIZONTAL) {
        for (int i = start_y; i <= end_y; i++) {
            bool obstruct_by_two = false;
            bool slice_tag = false;
            for (int j = start_x; j <= end_x; j++) {
                if (plate[i][j] == 1) {
                    slice_tag = true;
                    one_num++;
                }
                if (plate[i][j] == 2) {
                    obstruct_by_two = true;
                    two_num++;
                }
            }
            if (!obstruct_by_two && slice_tag && i != start_y && i != end_y) {
                pair<int, int> up_tetragon = divide(plate, start_x, start_y, end_x, i - 1, VERTICAL);
                pair<int, int> down_tetragon = divide(plate, start_x, i + 1, end_x, end_y, VERTICAL);
                result.first += up_tetragon.second * down_tetragon.second + up_tetragon.first * down_tetragon.first;
                result.second += up_tetragon.first * down_tetragon.second + up_tetragon.second * down_tetragon.first;
            }
        }
    }
    else {
        for (int i = start_x; i <= end_x; i++) {
            bool obstruct_by_two = false;
            bool slice_tag = false;
            for (int j = start_y; j <= end_y; j++) {
                if (plate[j][i] == 1) {
                    slice_tag = true;
                    one_num++;
                }
                if (plate[j][i] == 2) {
                    obstruct_by_two = true;
                    two_num++;
                }
            }
            if (!obstruct_by_two && slice_tag && i != start_x && i != end_x) {
                pair<int, int> left_tetragon = divide(plate, start_x, start_y, i - 1, end_y, HORIZONTAL);
                pair<int, int> right_tetragon = divide(plate, i + 1, start_y, end_x, end_y, HORIZONTAL);
                result.first += left_tetragon.second * right_tetragon.second + left_tetragon.first * right_tetragon.first;
                result.second += left_tetragon.first * right_tetragon.second + left_tetragon.second * right_tetragon.first;
            }
        }
    }
    if (one_num == 0 && two_num == 1) return {0, 1};
    else return result;
}

int main () {
    fill(&save_state[0][0][0][0][0], &save_state[19][19][19][19][1], -1);
    int n;
    cin >> n;
    vector< vector<int> >plate(n, vector<int>(n));
    int one_num = 0;
    int two_num = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> plate[i][j];
            if (plate[i][j] == 1) one_num++;
            if (plate[i][j] == 2) two_num++;
        }
    }
    if (one_num == 0 && two_num == 1) cout << 1 << endl;
    else {
        pair<int, int> horizonal = divide(plate, 0, 0, n - 1, n - 1, HORIZONTAL);
        pair<int, int> vertical = divide(plate, 0, 0, n - 1, n - 1, VERTICAL);
        int solution = horizonal.first + horizonal.second + vertical.first + vertical.second;
        if (solution == 0) cout << -1 << endl;
        else cout << solution << endl;
    }

    return 0;
}
*/

