#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(void)
{
    int n;
    int i;
    int temp;
    queue<int> q;

    cin>>n;
    for(i = 0; i < n; i++)
    {
        q.push(i+1);
    }

    while(q.size() > 1)
    {
        // 대기열의 선두 토큰을 제거
        q.pop();
        
        // 선두에 위치한 토큰을 대기열의 말단으로 이동시킨다.
        temp = q.front();
        q.pop();
        q.push(temp);
    }

    cout<<q.front()<<'\n';
    

}