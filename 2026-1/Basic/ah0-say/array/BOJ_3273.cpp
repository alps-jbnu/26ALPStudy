#include <iostream>
using namespace std;

int main()
{
    int arr[100001];
    int n, x;
    int y=0;
    
    cin>>n;
    for (int i=0; i<n;i++)
    {
        cin>>arr[i];
    }
    cin>> x;

    for (int i =0 ; i<n ; i++)
    {
       for (int j=i+1 ; j<n; j++)
       {
            if (arr[i]+arr[j]==x)
                y++;
       }
    }
    cout<< y;
    return 0;
}