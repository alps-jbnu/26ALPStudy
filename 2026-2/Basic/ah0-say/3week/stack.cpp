#include <iostream>
#include <string>
using namespace std;

const int MX= 1000005;
int dat[MX];
int pos;

void push(int x){
    dat[pos++]=x;
}

void pop(){
    pos--;
}

int top(){
    return dat[pos-1];
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    while(n--){
        string s;
        cin >> s;
        if(s=="push"){
            int x;
            cin >> x;
            push(x);
        }
        else if(s=="pop"){
            if(pos==0) cout << -1 << "\n";
            else{
                cout << top() << "\n";
                pop();
            }
        }
        else if(s=="size") cout << pos << "\n";
        else if(s=="empty") cout << (pos==0) << "\n";
        else if(s=="top"){
            if(pos==0) cout << -1 << "\n";
            else cout << top() << "\n";
        }
    }
}
