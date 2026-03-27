#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void inputData(vector<int>& vec);
int middle(vector<int>& vec);
int avg(vector<int>& vec);

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    vector<int> vec(5);
    inputData(vec);
    cout<<avg(vec)<<'\n';
    cout<<middle(vec)<<'\n'; 
    


    return 0;
}

void inputData(vector<int>& vec)
{
    int i;
    i = 0;
    for(i = 0; i < vec.size(); i++)
    {
        cin >> vec[i];
    }
}

int middle(vector<int>& vec)
{
    sort(vec.begin(), vec.end());
    return vec[vec.size() / 2];
}

int avg(vector<int>& vec)
{
    int result = 0;
    int i;
    for(i = 0; i < vec.size(); i++)
        result = result + vec[i];

    result = result / vec.size();

    return result;
}
