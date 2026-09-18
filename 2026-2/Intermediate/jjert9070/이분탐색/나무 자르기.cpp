#include <iostream>
#include <vector>
#include <algorithm>


long long sumFunction(std::vector<long long>& arr, long long select)
{
    long long sum = 0;
    for(size_t i = 0; i < arr.size(); i++)
    {
        if(arr[i] >= select)
        {
            sum = sum + (arr[i] - select);
        }
    }

    return sum;
}


long long getLowerBoundHeight(std::vector<long long>& arr, long long target)
{
    long long result;
    long long ans;
    long long start = 0;
    long long end = arr[arr.size() - 1];
    long long mid;

    while(start <= end)
    {
        mid = (start + end) / 2;
        result = sumFunction(arr, mid);
        if(result >= target)
        {
            ans = mid;
            start = mid + 1;
        }
        else if(result < target)
        {
            end = mid - 1;
        }
    }

    return ans;
}




int main()
{
    std::ios::sync_with_stdio(NULL);
    std::cin.tie(0);
    long long n;
    long long m;
    long long res;
    std::vector<long long> arr;
    std::cin>>n>>m;

    arr.resize(n);

    for(size_t i = 0; i < n; i++)
    {
        std::cin>>arr[i];
    }

    std::sort(arr.begin(), arr.end());

    res = getLowerBoundHeight(arr, m);

    std::cout<<res<<'\n';
    

    return 0;
    
}