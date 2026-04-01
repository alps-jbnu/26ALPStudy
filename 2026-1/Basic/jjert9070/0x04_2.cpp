#include <iostream>

using namespace std;
void traverse(int dat[], int pre[], int nxt[]);


int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    const int MX = 10000;
    int dat[MX], pre[MX], nxt[MX];
    // dat i번째 원소의 값
    // pre는 i번째 원소에 대한 이전 원소의 인덱스
    // nxt는 다음원소의 인덱스

    int unused = 1;
    fill(pre, pre+MX, -1); // 이전 인덱스가 들어 있는 배열을 전부 -1로
    fill(nxt, nxt+MX, -1); // 다음 인덱스가 들어 있는 배열을 전부 -1로
    // 0번째 인덱스는 사용하지 않을 거임

    nxt[0] = 2;
    dat[2] = 13;
    nxt[2] = 1;
    pre[2] = 0;

    dat[1] = 65;
    nxt[1] = 4;
    pre[1] = 2;

    dat[4] = 21;
    nxt[4] = 5;
    pre[4] = 1;

    dat[5] = 17;
    pre[5] = 4;

    traverse(dat, pre, nxt);
    
    return 0;
}

void traverse(int dat[], int pre[], int nxt[])
{
    int cur = nxt[0];
    while(cur != -1)
    {
        cout << dat[cur] << ' ';
        cur = nxt[cur];
    }
    cout << "\n\n";
}