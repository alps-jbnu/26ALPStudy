#include <iostream>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int compare (const void* a, const void* b){
    return (*(int*)a - *(int*)b);
}

// int main(){
//     int n;
//     cin >> n;//9
//     int arr[100000];

//     for (int i = 0; i < n; i++){
//         cin >> arr[i];
//     }

//     int x;
//     cin >> x;

//     int ansCounter = 0;

//     for(int a = 0; a < n; a++){
//         int temp = arr[a];
//         for(int b = 0; b < n; b++){
//             int temp2 = temp + arr[b];

//             if(temp2 == x){
//                 ansCounter++;
//             }
//         }
//     } // Brute Force Way     // TimeOut

//     cout << ansCounter / 2 << endl;

// }

int main(){
    int n;
    cin >> n;//9
    int arr[100000];

    for (int i = 0; i < n; i++){
        cin >> arr[i];  
    }

    int x;
    cin >> x; // x = ans

    qsort(arr, n, sizeof(*arr), compare);
    //sort(arr, arr + n);

    int L = 0;
    int R = n-1;
    int ans = 0;


    while(L < R){
        int temp = arr[L] + arr[R];

        if(temp == x) {
            ans++;
            L++;
            R--;
        } else if(temp < x) { // 미달이면, 좌측 이동
            L++;
        } else if(temp > x) {
            R--;
        }
    }

    cout << ans << '\n'; // endl 보다 '\n' 속도빠름
    return 0;
}