#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    int m;
    int temp;
    int count=0;

    cin>>n;
    cin>>m;
    deque<int> DQ(n);
    list<int> target;

    int i;

    for(i = 0; i < n; i++)
    {
        DQ[i] = i+1;
    }

    for(i = 0; i < m; i++)
    {
        cin>>temp;
        target.push_back(temp);

    }
    for(list<int>::iterator iter = target.begin(); iter != target.end(); iter++)
    {
        deque<int>::iterator location = find(DQ.begin(), DQ.end(), *iter);
        int DQ_target_index = distance(DQ.begin(), location);
        if(DQ.front() == *iter)
        {
            DQ.pop_front();
            continue;
        }
        else
        {
            if(DQ_target_index <= DQ.size() / 2)
            {
                // 오른쪽 으로 회전
                while(DQ.front() != *iter)
                {
                    temp = DQ.front();
                    DQ.push_back(temp);
                    DQ.pop_front();
                    count++;
                }
                DQ.pop_front();
                continue;
                
            }
            else if(DQ_target_index > DQ.size() / 2)
            {
                while(DQ.front() != *iter)
                {
                    temp = DQ.back();
                    DQ.push_front(temp);
                    DQ.pop_back();
                    count++;
                }
                DQ.pop_front();
                continue;
            }
        }
    }
    cout<<count<<'\n';
 
    return 0;
}