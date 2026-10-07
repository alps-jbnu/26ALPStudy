#include <iostream>
using namespace std;

int main()
{
    int arr[3], tmp;
    cin>>arr[0]>>arr[1]>>arr[2];
    
    for (int i=0; i<2; i++)
    {
        for (int j=i+1; j<3; j++)
        {
            if (arr[i]>arr[j])
            {
                tmp=arr[j];
                arr[j]=arr[i];
                arr[i]=tmp;
            }
        }
    }
    
    cout<<arr[0]<<" "<<arr[1]<<" "<<arr[2]; 
    return 0;
}