#include <bits/stdc++.h>
using namespace std;

int main() {
    stack<int> s;
    int n;
    string cmd;
    cin>>n;
    
    for (int i=0; i<n; i++) {
        cin>>cmd;
        
        if(cmd=="push") {
            int h;
            cin>>h;
            s.push(h);
        }
        
        if(cmd=="pop") {
            if(empty(s)) {
                cout<<-1<<"\n";
            }
            else {
                cout<<s.top()<<"\n";
                s.pop();
            }
        }
        
        if(cmd=="size") {
            cout<<s.size()<<"\n";
        }
        
        if(cmd=="empty") {
            cout<<s.empty()<<"\n";
        }
        
        if(cmd=="top") {
            if(empty(s)) {
                cout<<-1<<"\n";
            }
            else
                cout<<s.top()<<"\n";
        }
    }
    
    return 0;
}
