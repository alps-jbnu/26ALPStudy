#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int n;
    int i;
    int temp;
    int result = 0;
    list<int> li;

    cin>>n;
    for(i = 0; i < n; i++)
    {
        cin>>temp;
        li.push_back(temp);
    }
    for(list<int>::iterator it = li.begin(); it != li.end(); it++)
    {
        for(list<int>::iterator it_j = it; it_j != li.end(); it_j++)
        {
            if(it_j == it)
            {
                continue;
            }

            if(*it_j < *it)
            {
                result++;
            }
            else
            {
                break;
            }
        }

    }

    cout<<result<<'\n';
    return 0;

}