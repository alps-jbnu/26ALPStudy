#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

std::pair<int, int> selection(std::vector<int>& arr)
{
    std::pair<int, int> result;

    long long sum;
    long long sumAbs;
    int start = 0;
    int end = arr.size() - 1;
    long long minSumAbs = abs(arr[start] + arr[end]);


    while(start < end)
    {
        sum = arr[end] + arr[start];
        sumAbs = abs(sum);

        if(sumAbs <= minSumAbs)
        {
            minSumAbs = abs(sum);
            result = {arr[start], arr[end]};
        }


        if(sum <= 0)
        {
            start = start + 1;
        }
        else if(sum > 0)
        {
            end = end - 1;
        }
    }


    return result;
}




int main()
{
    std::ios::sync_with_stdio(NULL);
    std::cin.tie(0);
    int n;
    std::pair<int, int> result;
    std::vector<int> arr;
    std::cin>>n;
    arr.resize(n);

    for(size_t i = 0; i < arr.size(); i++)
    {
        std::cin>>arr[i];;
    }
    
    result = selection(arr);

    std::cout<<result.first<<" "<<result.second<<'\n';


    return 0;
}