#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int arr[26] = {0, };
    string S;
    cin >> S;
    for(int i = 0; i < S.length(); i++)
    {
        arr[S[i] - 'a']++;
    }
    for(int i = 0; i < 26; i++) cout << arr[i] << " ";
    return 0;
}
