#include <iostream>
#include <vector>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n;
    int target;
    int i;
    int count=0;
    cin >> n;
    vector<int> vec(n, 0);
    vector<int> e_counter(2000001, 0);

    
    for(i = 0; i < vec.size(); i++)
    {
        cin >> vec[i];
    }
    cin >> target;
    for(i = 0; i < vec.size(); i++)
    {
        e_counter[vec[i]] = 1;
    }
    
    for(i = 0; i < vec.size(); i++)
    {
        if(target - vec[i] <= 0)
        {
            continue;
        }
        if(e_counter[target-vec[i]] == 1)
        {
            count++;
        }
    }
    cout<<count/2<<'\n';

    

    return 0;

}