#include <iostream>
#include <list>
#include <string>
using namespace std;

int main() {
    string str;
    cin>>str;

    list<char> li(str.begin(),str.end());

    list<char>::iterator cursor = li.end();

    int m;
    cin>>m;

    while (m--) {
        char cmd;
        cin>>cmd;
        if(cmd=='L'){
            if(cursor!=li.begin())
               cursor--;
        }
        if(cmd=='D') {
            if(cursor!=li.end())
                cursor++;
        }
        if(cmd=='B') {
            if(cursor!=li.begin()) {
                list<char>::iterator temp=cursor;
                temp--;

                li.erase(temp);
            }
        }
        if(cmd=='P') {
            char h;
            cin>>h;

            li.insert(cursor,h);
        }
    }
    for(list<char>::iterator it=li.begin(); it != li.end(); it++) {
        cout<<*it;
    }
    cout<<"\n";

    return 0;
}