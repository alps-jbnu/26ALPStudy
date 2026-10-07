#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int alp[26] = { 0, }; 
    string s;

    cin >> s;
    for (int i = 0; i < s.length(); i++) {
        alp[s[i] - 'a']++;
    }

    for (int j = 0; j < 26; j++) {
        cout << alp[j] << ' '; // 공백 추가
    }
    return 0;
}
