#include <iostream>
#include <vector>

using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    int i;
    int target;
    int data;
    int counter = 0;
    vector<int> vec;
    cin >> n;
    vec.resize(n);

    for(i = 0; i < n; i++)
    {
        cin>>vec[i];
    }

    cin >> target;

    for(i = 0; i < n; i++)
    {
        if(vec[i] == target)
        {
            counter++;
        }
    }

    cout << counter <<'\n';
    


    return 0;
}