#include <bits/stdc++.h>
#include <iostream>

using namespace std;


int main(void)
{
    stack<int> stk;
    int n;
    int i;
    int x;
    string st_data;
    
    cin>>n;
    for(i = 0; i < n; i++)
    {
        cin>>st_data;

            if(st_data.compare("push") == 0)
            {
                cin>>x;
                stk.push(x);
            }
            else if(st_data.compare("pop") == 0)
            {
                if(stk.empty())
                {
                    cout<<"-1"<<'\n';
                    continue;
                }
                else
                {
                    cout<<stk.top()<<'\n';
                    stk.pop();
                }
            }
            else if(st_data.compare("size") == 0)
            {
                cout<<stk.size()<<'\n';
            }
            else if(st_data.compare("empty") == 0)
            {
                if(stk.empty())
                {
                    cout<<"1"<<'\n';
                    continue;
                }
                else
                {
                    cout<<"0"<<'\n';
                }
            }
            else if(st_data.compare("top") == 0)
            {
                if(stk.empty())
                {
                    cout<<"-1"<<'\n';
                    continue;
                }
                else
                {
                    cout<<stk.top()<<'\n';
                }
            }
    
    }

    return 0;
}