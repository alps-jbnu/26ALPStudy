#include <iostream>
#include <cstring>
using namespace std;

int main(){
    char S[101];
    cin >> S;

    int atoz[26];
    memset(atoz, 0, sizeof(atoz));

    int len = strlen(S);
    for(int i = 0; i < len; i++){
        atoz[S[i] - (97)] ++;
    }

    for(int i = 0; i < 26; i++) {
        cout << atoz[i] << " ";
    }
    
    return 0;
}