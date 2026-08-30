#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int main(void)
{
    int n;
    cin >> n;
    vector<int> arr(n);
    int L;
    int i;
    int j;
    cin>>L;
    list<int> windows;
    int min = INT_MAX;
 
    list<int> D;

    for(i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    for(i = 0; i < L; i++)
    {
        windows.push_back(arr[i]);
    }

    for(i = L; i <= n; i++)
    {
         for(list<int>::iterator it = windows.begin(); it != windows.end(); it++)
        {
            if(*it < min)
            {
                min = *it;
            }
        }
    
        D.push_back(min);
        windows.pop_front();
        windows.push_back(arr[i]);
        min = INT_MAX;
    }
   
    for(list<int>::iterator it = D.begin(); it != D.end(); it++)
    {
        cout<<*it<<' ';
    }
    cout<<'\n';
    return 0;
}