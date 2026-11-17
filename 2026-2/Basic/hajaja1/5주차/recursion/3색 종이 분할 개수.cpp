#include <bits/stdc++.h>
using namespace std;

const int MAX = 2187;
int arr[MAX][MAX];
int one=0, zero=0, mone=0;

void threebythree(int N, int a, int b) { //N은 행렬의 가로세로 길이임, arr은 전체 배열, a,b는 배열의 시작 좌표임
    if (N == 1) { // 행렬의 길이가 1이면 행렬의 요소가 1개 임을 의미하므로 그 요소의 값과 같은 변수를 1증가시킴
        switch (arr[a][b]) {
        case -1: mone++; return;
        case  0: zero++; return;
        case  1: one++;  return;
        }
    }
    for (int i = 0; i < N; i++) { // 현재 행렬의 길이N만큼 이중 반복문으로 모든 요소의 값을 검사함.
        for (int j = 0; j < N; j++) {
            if (arr[a][b] != arr[a + i][b + j]) {
                //행렬의 요소의 값이 일치하지 않을때 3by3으로 나누어서 재귀하여 부른다.
                threebythree(N / 3, a, b);
                threebythree(N / 3, a + N / 3, b);
                threebythree(N / 3, a + N / 3 * 2, b);
                threebythree(N / 3, a, b + N / 3);
                threebythree(N / 3, a + N / 3, b + N / 3);
                threebythree(N / 3, a + N / 3 * 2, b + N / 3);
                threebythree(N / 3, a, b + N / 3 * 2);
                threebythree(N / 3, a + N / 3, b + N / 3 * 2);
                threebythree(N / 3, a + N / 3 * 2, b + N / 3 * 2);
                return;
            }
        }
    }
    //이중반복문을 무사히 마쳤으면 이 행렬의 모든 요소가 같은 숫자임을 의미하므로 행렬의 아무요소의 값과 일치하는 변수를 1증가시킴
    switch (arr[a][b]) {
    case -1: mone++; return;
    case  0: zero++; return;
    case  1: one++;  return;
    }
}
    int main(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int N = 0;
        cin >> N;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> arr[i][j];
            }
        }
        /*for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cout << arr[i][j]<<' ';
            }
            cout << '\n';
        }*/
        threebythree(N, 0, 0);
        cout << mone << '\n' << zero << '\n' << one;
        return 0;
    }
