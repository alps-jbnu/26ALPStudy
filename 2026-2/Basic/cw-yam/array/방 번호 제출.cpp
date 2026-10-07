#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    string N;
    int arr[10] = {0, };
    int max = 0;
    cin >> N;
    for(int i = 0; i < N.length(); i++)
    {
        arr[N[i] - '0']++;
    }
    for(int i =0; i < 10; i++)
    {
        if (i == 6 || i == 9){
            int x = (arr[6] + arr[9] + 1)/2;
            if(max < x) max = x;
        }
        else if(max < arr[i]) max = arr[i];
    }
    cout << max;
    return 0;
}
