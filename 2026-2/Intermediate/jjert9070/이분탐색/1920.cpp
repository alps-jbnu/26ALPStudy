#include <iostream>
#include <vector>
#include <algorithm>



bool binarySearch(std::vector<int>& arr, int target)
{
    int startIndex = 0;
    int endIndex = arr.size() - 1;
    int midIndex;

    while(startIndex <= endIndex)
    {
        midIndex = (startIndex + endIndex) / 2;

        if(arr[midIndex] > target)
        {
            endIndex = midIndex - 1;
        }
        else if(arr[midIndex] < target)
        {
            startIndex = midIndex + 1;
        }
        else if(arr[midIndex] == target)
        {
            return true;
        }
    }

    return false;
}




int main()
{
    std::ios::sync_with_stdio(NULL);
    std::cin.tie(0);
    int n;
    int m;
    std::vector<int> arr;
    std::vector<int> query;
    std::cin>>n;
    arr.resize(n);

    for(size_t i = 0; i < arr.size(); i++)
    {
        std::cin>>arr[i];
    }

    std::sort(arr.begin(), arr.end());

    std::cin>>m;
    query.resize(m);

    for(size_t i = 0; i < query.size(); i++)
    {
        std::cin>>query[i];
    }

    for(size_t j = 0; j < query.size(); j++)
    {
        if(binarySearch(arr, query[j]) == true)
        {
            std::cout<<"1"<<'\n';
        }
        else
        {
            std::cout<<"0"<<'\n';
        }
    }


    return 0;
    
}