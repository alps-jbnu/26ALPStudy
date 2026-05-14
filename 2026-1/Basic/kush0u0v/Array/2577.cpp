#include<iostream>
#include<cstring>
using namespace std;

int main(){
    int a, b, c;
    cin >> a >> b >> c;
    int ans = a*b*c;
    
    int arr[10];
    memset(arr, 0, sizeof(arr));

    while(ans >= 1){
        int temp = ans % 10;
        arr[temp] ++;
        ans = ans / 10;
    }

    for(int i = 0; i < 10; i++){
        cout << arr[i] << endl;
    }

    return 0;
}
