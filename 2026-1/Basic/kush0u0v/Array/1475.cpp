#include <iostream>
#include <cstring>

using namespace std;

int main(){
    int arr[9];
    memset(arr, 0, sizeof(arr));

    int input;
    cin >> input;
    int ans = 0;

    for(int i = 0; ; i++){
        int temp = input % 10;
        arr[temp] ++;
        input = input / 10;
        
        if (ans < arr[temp]){
            ans = arr[temp];
        }

        if (input < 10) {
            arr[input] ++;
            break;
        }
    }
    // 6 and 9는 예외
    cout << ans << '\n';
}

// ////
// #include <stdio.h>

// int main() {
//     int n;
//     scanf("%d", &n);

//     int c[10] = {0};

//     if (n == 0) printf("1\n");

//     while(n>0){
//         int mono = n % 10;
//         c[mono]++;
//         n /= 10;
//     }

//     int six_nine = (c[6] + c[9] + 1) / 2;
//     c[6] = six_nine;
//     c[9] = six_nine;

//     int ans = 0;
//     for (int i = 0; i < 10; i++){
//         if(c[i] > ans)
//             ans = c[i];
//     }

//     printf("%d", ans);
// }