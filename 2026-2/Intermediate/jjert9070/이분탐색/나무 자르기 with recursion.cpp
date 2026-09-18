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

long long getLowerBoundHeight(std::vector<long long>& arr, long long start, long long end, long long target, long long result)
{    
    if(start > end)
    {
        return result;
    }

    long long mid = (start + end) / 2;
    long long now = sumFunction(arr, mid);
    long long ans = 0;
    long long ret_value = 0;


    if(now >= target)
    {
        ans = mid;
        start = mid + 1;
        ret_value = getLowerBoundHeight(arr, start, end, target, ans);
    }
    else if(now < target)    
    {
        end = mid - 1;
        ret_value = getLowerBoundHeight(arr, start, end, target, result);
    }




    return ret_value;
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

    res = getLowerBoundHeight(arr, 0, arr[arr.size() - 1], m, 0);

    std::cout<<res<<'\n';
    

    return 0;
    
}