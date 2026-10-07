#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

int main()
{
    deque<int> d;
    int N, key, count = 0;
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        int x;
        cin >> x;
        d.push_back(x);
    }
    sort(d.begin(), d.end());
    cin >> key;
    
    if(key > 50)
    {
        while(!d.empty() && key <= d.back()){
            if(key == d.back()) {d.pop_back(); count++;}
            else d.pop_back();
        }
    }
    else{
        while(!d.empty() && key >= d.front()){
            if((key == d.front())) {d.pop_front(); count++;}
            else d.pop_front();
        }
    }
    cout << count;
    return 0;
}
