#include <iostream>
#include <vector>
#include <algorithm>

int binarySearch(std::vector<int>& arr, int target)
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
            return midIndex;
        }
        
    }



    return -1;
}


int main()
{
    std::ios::sync_with_stdio(NULL);
    std::cin.tie(0);

    int nA;
    int nB;
    std::vector<int> arrA;
    std::vector<int> arrB;

    std::cin>>nA;
    std::cin>>nB;

    arrA.resize(nA);
    arrB.resize(nB);

    for(size_t i = 0; i < arrA.size(); i++)
    {
        std::cin>>arrA[i];
    }

    for(size_t j = 0; j < arrB.size(); j++)
    {
        std::cin>>arrB[j];
    }

    std::sort(arrA.begin(), arrA.end());
    std::sort(arrB.begin(), arrB.end());


    for(size_t u = 0; u < arrB.size(); u++)
    {
        int targetIndex = binarySearch(arrA, arrB[u]);
        if(targetIndex == -1)
        {
            continue;
        }
        arrA.erase(arrA.begin() + targetIndex);
    }

    if(arrA.size() == 0)
    {
        std::cout<<"0";
    }
    else
    {
        std::cout<<arrA.size()<<'\n';
        for(size_t w = 0; w < arrA.size(); w++)
        {
            std::cout<<arrA[w]<<" ";
        }
    }



    std::cout<<'\n';

    return 0;
}