#include <iostream>
#include <bits/stdc++.h>

using namespace std;


int main(void)
{
    int n;
    cin >> n;
    vector<int> vec(n);
    vector<int> result(n, 0);
    int i;
    int j;

    for(i = 0; i < vec.size(); i++)
    {
        cin>>vec[i];
    }
    int flag;
    for(i = 0; i < vec.size(); i++)
    {
        for(j = 0; j<i; j++)
        {
            if(vec[j] >= vec[i])
            {
                result[i] = j + 1;
            }
        }
    }

    for(i = 0; i < vec.size(); i++)
    {
        cout<<result[i]<<' ';
    }

    return 0; 
}