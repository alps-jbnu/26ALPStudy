#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

std::vector<int> pickUpDish(std::vector<int>& arr, int start_index, int k)
{
    std::vector<int> dishes;

    dishes.resize(k, 0);

    for(size_t i = 0; i < k; i++)
    {
        dishes[i] = arr[(start_index + i) % arr.size()];
    }

    return dishes;
}

std::vector<int> compressedArr(std::vector<int>& arr, int coupon)
{
    std::vector<int> arr_compressed;
    arr_compressed.resize(arr.size(), 0);

    std::copy(arr.begin(), arr.end(), arr_compressed.begin());

    arr_compressed.resize(arr_compressed.size() + 1);

    arr_compressed[arr_compressed.size() - 1] = coupon;

    std::sort(arr_compressed.begin(), arr_compressed.end());

    auto it = std::unique(arr_compressed.begin(), arr_compressed.end());

    arr_compressed.erase(it, arr_compressed.end());

    return arr_compressed;
}


int main()
{
    std::ios::sync_with_stdio(NULL);
    std::cin.tie(0);

    int n;
    int d;
    int k;
    int c;
    int start = 0;

    std::vector<int> arr;
    std::priority_queue<int> q;
    std::cin>>n>>d>>k>>c;

    arr.resize(n, 0);

    for(size_t i = 0; i < arr.size(); i++)
    {
        std::cin>>arr[i];
    }


    int count = 0;
    while(start < arr.size())
    {
        std::vector<int> dishes;
        std::vector<int> arr_compressed;

        dishes = pickUpDish(arr, start, k);
        arr_compressed = compressedArr(dishes, c);
        count = arr_compressed.size();

        q.push(count);
        start = start + 1;
    }




    std::cout<<q.top()<<'\n';







    return 0;
}