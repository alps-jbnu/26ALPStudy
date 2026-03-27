#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void nanjangee(vector<int>& v);
int sum(vector<int>& v);

int main()
{    
    cin.tie(0);
    ios::sync_with_stdio(0);
    vector<int> vec(9);
    int i;
    nanjangee(vec);
    sort(vec.begin(), vec.end());
    for(i = 0; i < vec.size(); i++)
    {
        if(vec[i] == 0)
        {
            continue;
        }
        cout << vec[i] << '\n';
    }

    return 0;

}

void nanjangee(vector<int>& v)
{
    int i, j;
    int data_1, data_2;
    int result;

    for(i = 0; i < v.size(); i++)
    {
        cin >> v[i];
    }
     // 2개의 원소를 빼서 더해본다.
    for(i = 0; i < v.size()-1; i++)
    {
        data_1 = v[i];
        v[i] = 0;
        for(j = i + 1; j < v.size(); j++)
        {
            data_2 = v[j];
            v[j] = 0;
            if(sum(v) == 100)
                return;
            else
                v[j] = data_2;
        }
        v[i]=data_1;
    }

}

int sum(vector<int>& v)
{
    int i;
    int result = 0;
    for(i = 0; i < v.size(); i++)
    {
        result += v[i];
    }
    return result;
}

