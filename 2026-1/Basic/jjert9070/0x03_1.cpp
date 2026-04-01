#include <bits/stdc++.h>
using namespace std;

void insert(int idx, int num, int arr[], int& len)
{
    int arr_temp[100] = {0};
    int i;

    for(i = 0; i < idx; i++)
    {
        arr_temp[i] = arr[i];
    }
    arr_temp[idx] = num;
    for(i = 0; i < len - idx; i++)
    {
        arr_temp[idx+i+1] = arr[idx + i];
    }
    len++;
    for(i = 0; i < len; i++)
    {
        arr[i] = arr_temp[i];
    }


}

void erase(int idx, int arr[], int& len)
{
    int arr_temp[100] = {0};
    int i;
    for(i = 0; i < len; i++)
    {
        arr_temp[i] = arr[i];
        if(i == idx)
        {
            arr_temp[i] = arr[i+1];
        }
    }
    --len;
    for(i = 0; i < len; i++)
    {
        arr[i] = arr_temp[i];
    }
}

void printArr(int arr[], int& len)
{
    for(int i = 0; i < len; i++) cout << arr[i] << ' ';
    cout << "\n\n";
}

void insert_test()
{
    int len = 4;
    int arr[100] = {20, 30, 40, 50, 0,};
    printArr(arr, len);
    insert(2, 90, arr, len);
    printArr(arr, len);
}

void erase_test()
{
    int len = 4;
    int arr[100] = {20, 30, 40, 50, 0,};
    printArr(arr, len);
    erase(2, arr, len);
    printArr(arr, len);
}



int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    //insert_test();
    erase_test();

    return 0;
}