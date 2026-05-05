#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(void)
{
    queue<int> q;
    int n;
    int x;
    string str_data;
    int i;

    cin>>n;
    for(i = 0; i < n; i++)
    {
        cin>>str_data;
        
        if(str_data.compare("push") == 0)
        {
            cin>>x;
            q.push(x);
        }
        else if(str_data.compare("pop") == 0)
        {
            if(q.empty())
            {
                cout<<"-1"<<'\n';
            }
            else
            {
                cout<<q.front()<<'\n';
                q.pop();
            }
        }
        else if(str_data.compare("size") == 0)
        {
            cout<<q.size()<<'\n';
        }
        else if(str_data.compare("empty") == 0)
        {
            if(q.empty())
            {
                cout<<"1"<<'\n';
            }
            else
            {
                cout<<"0"<<'\n';
            }
        }
        else if(str_data.compare("front") == 0)
        {
            if(q.empty())
            {
                cout<<"-1"<<'\n';
            }
            else
            {
                cout<<q.front()<<'\n';
                
            }
        }
        else if(str_data.compare("back") == 0)
        {
            if(q.empty())
            {
                cout<<"-1"<<'\n';
            }
            else
            {
                cout<<q.back()<<'\n';
            }
        }
    }
    
    return 0;   
}