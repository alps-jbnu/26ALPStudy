#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    vector<int> answer(n, -1);
    vector<int> st;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++) {
        while (!st.empty() && arr[st.back()] < A[i]) {
            answer[st.back()] = arr[i];
            st.pop_back();
        }

        st.push_back(i);
    }

    for (int i = 0; i < n; i++) {
        cout << answer[i] << ' ';
    }

    return 0;
}
