#include <iostream>
#include <algorithm>

using namespace std;

int arr_A[500000];
int arr_B[500000];

int ans[500000];

int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> arr_A[i];
    for(int i = 0; i < m; i++)
        cin >> arr_B[i];
    sort(arr_A, arr_A + n);
    sort(arr_B, arr_B + m);
    int k = 0;
    for(int i = 0; i < n; i++) {
        if(!binary_search(arr_B, arr_B + m, arr_A[i])) {
            ans[k++] = arr_A[i];
        }
    }
    cout << k << "\n";
    for(int i = 0; i < k; i++) {
        cout << ans[i] << " ";
    }
    return 0;
}