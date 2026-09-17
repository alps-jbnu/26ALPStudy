#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    int arr[5] = {0, };
    int count = 0;
    for(int i = 0; i < 5; i++)
    {
        cin >> arr[i];
        count += arr[i];
    }
    sort(arr, arr + 5);
    cout << count / 5 << "\n" << arr[2];
    return 0;
}
