#include <bits/stdc++.h>
using namespace std;

void insert(int idx, int num, int arr[], int& len)
{   
    
}

void erase(int idx, int arr[], int& len)
{

}

void printArr(int arr[], int& len)
{
    for(int i = 0; i < len; i++) cout << arr[i] << ' ';
    cout << "\n\n";
}

void insert_test()
{
    int len = 4;
    int arr[4] = {20, 30, 40, 50};
    insert(2, 90, arr, len);
    printArr(arr, len);
}

void erase_test()
{

}



int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    insert_test();
    erase_test();

    return 0;
}