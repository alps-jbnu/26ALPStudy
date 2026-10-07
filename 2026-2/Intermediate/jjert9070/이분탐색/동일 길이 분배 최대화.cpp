#include <iostream>
#include <vector>
#include <algorithm>


unsigned long long getTotalQuotient(std::vector<unsigned long long>& arr, unsigned long long start, unsigned long long end, unsigned long long select)
{
    unsigned long long totalQuotient = 0;

    for(size_t i = start; i < end; i++)
    {
        totalQuotient = totalQuotient + (arr[i] / select);   
    }

    return totalQuotient;
}


unsigned long long findOptimalStickSize(std::vector<unsigned long long>& arr, unsigned long long start, unsigned long long end, unsigned long long m)
{
    unsigned long long totalQuotient = 0;
    unsigned long long mid_val;
    unsigned long long max_val = arr[arr.size() - 1];
    unsigned long long min_val = 1;
    unsigned long long answer = 0;

    while (min_val <= max_val)
    {
        mid_val = (min_val + max_val) / 2;
        totalQuotient = getTotalQuotient(arr, start, end, mid_val);

        if(totalQuotient >= m)
        {
            answer = mid_val;
            min_val = mid_val + 1;
        }
        else if(totalQuotient < m)
        {
            max_val = mid_val - 1;
        }
    }

    return answer;
}


int main()
{

    std::ios::sync_with_stdio(NULL);
    std::cin.tie(0);


    unsigned long long m;
    unsigned long long n;
    unsigned long long result;
    std::vector<unsigned long long> arr;

    std::cin>>m>>n;
    arr.resize(n);

    for(size_t i = 0; i < arr.size(); i++)
    {
        std::cin>>arr[i];
    }

    std::sort(arr.begin(), arr.end());
    result = findOptimalStickSize(arr, 0, arr.size(), m);

    std::cout<<result<<'\n';

    return 0;

}