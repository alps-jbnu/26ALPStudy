#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int arr1[26] = {0, };
    int arr2[26] = {0, };
    int count = 0;
    string S1, S2;
    cin >> S1 >> S2;
    for(int i = 0; i < S1.length(); i++)
    {
        arr1[S1[i] - 'a']++;
    }
    for(int i = 0; i < S2.length(); i++)
    {
        arr2[S2[i] - 'a']++;
    }
    for(int i = 0; i < 26; i++)
    {
        if(arr1[i] > arr2[i]) count += arr1[i] - arr2[i];
        else if(arr1[i] < arr2[i]) count += arr2[i] - arr1[i];
    }
    cout << count;
    return 0;
}
