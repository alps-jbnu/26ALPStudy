#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n,k;
    cin >> n >> k;

    vector<long long> v(n+1);
    for(int i=0; i<n; i++)
    {
        cin>> v[i];
    }

    int left = 0;
    int Oddcnt = 0;
    int ans = 0;

    for(int right = 0; right < n; right++)
    {
        if(v[right] % 2 == 1)
            Oddcnt++;

        while(Oddcnt > k)
        {
            if(v[left] % 2 == 1)
                Oddcnt--;
            left++;
        }

        ans = max(ans, right - left + 1 - Oddcnt);
    }

    cout<<ans<<"\n";

    return 0;
}