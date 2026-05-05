#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(void)
{
    int n = 0;
    cin >> n;
    list<int> data;

    int i = 0;
    int temp;
    int result = 0;

    for(i = 0; i < n; i++)
    {
        cin>>temp;
        if(temp == 0)
        {
            data.pop_back();
            continue;
        }
        data.push_back(temp);        
    }

    for(list<int>::iterator iter = data.begin(); iter != data.end(); iter++)
    {
        result += *iter;
    }

    cout<<result<<'\n';
    
}