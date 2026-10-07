#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int arr[10] = {0, };
    int A, B, C;
    cin >> A >> B >> C;
    string S = to_string(A * B * C);
    for(int i = 0; i < S.length(); i++)
    {
        arr[S[i] - '0']++;
    }
    for(int i = 0; i < 10; i++)
    {
        cout << arr[i] << "\n";
    }
    return 0;
}
