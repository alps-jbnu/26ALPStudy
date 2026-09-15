#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>


int selection(std::vector<int>& arr, int m)
{
    int start = 0;
    int end = 0;
    long long minDiff = INT_MAX;

    while(start < arr.size() && end < arr.size())
    {
        if(arr[end] - arr[start] >= m && arr[end] - arr[start] < minDiff)
        {
            minDiff = arr[end] - arr[start];
        }

        if(arr[end] - arr[start] < m)
        {
            end = end + 1;
        }
        else if(arr[end] - arr[start] >= m)
        {
            start = start + 1;
        }
    }





    return minDiff;
}



int main()
{
    std::ios::sync_with_stdio(NULL);
    std::cin.tie(0);
    int n;
    int m;
    int result;
    std::vector<int> arr;
    std::cin>>n>>m;

    arr.resize(n);

    for(size_t i = 0; i < n; i++)
    {
        std::cin>>arr[i];
    }


    std::sort(arr.begin(), arr.end());

    result = selection(arr, m);
    std::cout<<result<<'\n';


    return 0;
}