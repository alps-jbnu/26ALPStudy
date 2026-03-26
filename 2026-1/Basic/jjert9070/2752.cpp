#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> vec(3);
    int i;
    cin >> vec[0] >> vec[1] >> vec[2];
    sort(vec.begin(), vec.end());
    for(i=0;i<vec.size();i++)
        cout<<vec[i]<<' ';

    return 0;
}