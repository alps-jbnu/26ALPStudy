#include <iostream>
#include <vector>
#include <algorithm>


bool compareFunc(std::vector<std::vector<long long>>& arr, long long row_index_1, long long row_index_2)
{

    for(size_t i = 0; i < arr[0].size() - 2 + 1; i++)
    {
        for(size_t j = i + 1; j < arr[0].size(); j++)
        {
            if (arr[row_index_1][i] < arr[row_index_1][j] && arr[row_index_2][i] < arr[row_index_2][j])
            {
                continue;
            }
            else if (arr[row_index_1][i] > arr[row_index_1][j] && arr[row_index_2][i] > arr[row_index_2][j])
            {
                continue;
            }
            else if (arr[row_index_1][i] == arr[row_index_1][j] && arr[row_index_2][i] == arr[row_index_2][j])
            {
                continue;
            }
            else
            {
                return false; 
            }
        }
    }

    return true;
}

long long countIsomorphism(std::vector<std::vector<long long>>& arr)
{
    long long count = 0;

    for(size_t i = 0; i < arr.size() - 2 + 1; i++)
    {
        for(size_t j = i + 1; j < arr.size(); j++)
        {
            if(compareFunc(arr, i, j) == true)
            {
                count++;
            }
        }

    }

    return count;
}


int main()
{
    std::ios::sync_with_stdio(NULL);
    std::cin.tie(0);
    int n;
    int m;
    int result;
    std::vector<std::vector<long long>> arr;
    std::vector<std::vector<long long>> arr_copy;
    std::vector<std::vector<long long>> arr_compressed;
    std::cin>>m>>n;

    arr.resize(m, std::vector<long long>(n, 0));
    arr_copy.resize(m, std::vector<long long>(n, 0));
    arr_compressed.resize(m, std::vector<long long>(n, 0));


    for(size_t i = 0; i < arr.size(); i++)
    {
        for(size_t j = 0; j < arr[0].size(); j++)
        {
            std::cin>>arr[i][j];
        }
        std::copy(arr[i].begin(), arr[i].end(), arr_copy[i].begin());
        std::sort(arr_copy[i].begin(), arr_copy[i].end());
        auto it = std::unique(arr_copy[i].begin(), arr_copy[i].end());
        std::fill(it, arr_copy[i].end(), -1);

        for(size_t k = 0; k < arr[i].size(); k++)
        {
            arr_compressed[i][k] = std::lower_bound(arr_copy[i].begin(), it, arr[i][k]) - arr_copy[i].begin();
        }
    }

    int count = 0;

    for(size_t i = 0; i < arr_compressed.size() - 1; i++)
    {
        for(size_t j = i + 1; j < arr_compressed.size(); j++)
        {
            if(arr_compressed[i] == arr_compressed[j])
            {
                count = count + 1;
            }
        }
    }

    std::cout<<count<<'\n';

    return 0;
}