//
// Created by 손민균 on 26. 10. 13.
//
#include <iostream>
#include <string>
#include <vector>
using namespace std;

string divide_and_conquer(vector< vector<string> > &plate, int length, int start_x, int start_y) {
    if (length == 1) return plate[start_y][start_x];
    vector< vector<string> > mini_plate(2, vector<string>(2));
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            mini_plate[i][j] = divide_and_conquer(plate, length / 2, start_x + j * length/2, start_y + i * length/2);
        }
    }
    string& criteria = mini_plate[0][0];
    bool same_flag = true;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            if (mini_plate[j][i] != criteria) same_flag = false;
        }
    }
    if (same_flag && criteria.length() == 1) {
        return mini_plate[0][0];
    }
    else {
        string return_string = "(";
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                return_string += mini_plate[i][j];
            }
        }
        return_string += ")";
        return return_string;
    }
}

int main() {
    int n;
    cin >> n;
    vector< vector<string> > plate(n, vector<string>(n));
    for (int i = 0; i < n; i++) {
        string input;
        cin >> input;
        for (int j = 0; j < n; j++) {
            plate[i][j] = input[j];
        }
    }
    string return_string = divide_and_conquer(plate, n, 0, 0);
    cout << return_string << endl;
    return 0;
}