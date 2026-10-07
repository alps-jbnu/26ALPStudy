#include <bits/stdc++.h>
using namespace std;

int main() {
    queue<int> q;
    int n;
    cin>>n;
    
    for(int i=0; i<n; i++) {
        string cmd;
        cin>>cmd;
        
        if(cmd=="push") {
            int h;
            cin>>h;
            q.push(h);
        }
        
        if(cmd=="pop") {
            if(empty(q)) {
                cout<<-1<<"\n";
            }
            else {
                cout<<q.front()<<"\n";
                q.pop();
            }
        }
        
        if(cmd=="size") {
            cout<<q.size()<<"\n";
        }
        
        if(cmd=="empty") {
            cout<<q.empty()<<"\n";
        }
        
        if(cmd=="front") {
            if(empty(q)) {
                cout<<-1<<"\n";
            }
            else
                cout<<q.front()<<"\n";
        }
        
        if(cmd=="back") {
            if(empty(q)) {
                cout<<-1<<"\n";
            }
            else
                cout<<q.back()<<"\n";
        }
    }
    
    return 0;
}
