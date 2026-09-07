#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    int i;
    string command;
    int x;
    int temp;
    deque<int> dq;

    for(i = 0; i < n; i++)
    {
        cin>>command;
        if(command.compare("push_front") == 0)
        {
            cin>>x;
            dq.push_front(x);
        }
        else if(command.compare("push_back") == 0)
        {
            cin>>x;
            dq.push_back(x);
        }
        else if(command.compare("pop_front") == 0)
        {
            if(dq.empty())
            {
                cout<<"-1"<<'\n';
            }
            else
            {
                temp = dq.front();
                dq.pop_front();
                cout<<temp<<'\n';
            }
        }
        else if(command.compare("pop_back") == 0)
        {
            if(dq.empty())
            {
                cout<<"-1"<<'\n';
            }
            else
            {
                temp = dq.back();
                dq.pop_back();
                cout<<temp<<'\n';
            }
        }
        else if(command.compare("size") == 0)
        {
            cout<<dq.size()<<'\n';
        }
        else if(command.compare("empty") == 0)
        {
            if(dq.empty())
            {
                cout<<"1"<<'\n';
            }
            else
            {
                cout<<"0"<<'\n';
            }
        }
        else if(command.compare("front") == 0)
        {
            if(dq.empty())
            {
                cout<<"-1"<<'\n';
            }
            else
            {
                cout<<dq.front()<<'\n';
            }
        }
        else if(command.compare("back") == 0)
        {
            if(dq.empty())
            {
                cout<<"-1"<<'\n';
            }
            else
            {
                cout<<dq.back()<<'\n';
            }
        }
    }


    return 0;
}