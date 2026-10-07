#include <bits/stdc++.h>
using namespace std;

int main() {
    deque<int> d;
    int n;
    cin>>n;
    
    for(int i=0; i<n; i++) {
        string cmd;
        cin>>cmd;
        
        if(cmd=="push_front") {
            int h;
            cin>>h;
            d.push_front(h);
        }

        if(cmd=="push_back") {
            int h;
            cin>>h;
            d.push_back(h);
        }
        
        if(cmd=="pop_front") {
            if(empty(d)) {
                cout<<-1<<"\n";
            }
            else {
                cout<<d.front()<<"\n";
                d.pop_front();
            }
        }

        if(cmd=="pop_back") {
            if(empty(d)) {
                cout<<-1<<"\n";
            }
            else {
                cout<<d.back()<<"\n";
                d.pop_back();
            }
        }
        
        if(cmd=="size") {
            cout<<d.size()<<"\n";
        }
        
        if(cmd=="empty") {
            cout<<d.empty()<<"\n";
        }
        
        if(cmd=="front") {
            if(empty(d)) {
                cout<<-1<<"\n";
            }
            else
                cout<<d.front()<<"\n";
        }
        
        if(cmd=="back") {
            if(empty(d)) {
                cout<<-1<<"\n";
            }
            else
                cout<<d.back()<<"\n";
        }
    }
    
    return 0;
}
