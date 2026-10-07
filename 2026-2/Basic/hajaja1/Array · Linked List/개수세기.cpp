#include <stdio.h>

int main() {
    int N = 0;
    scanf("%d",&N); //정수의개수 N입력
    int a[N];
    for(int i =0;i<N;i++){ // 목록 입력
        scanf("%d", &a[i]);
    }
    int v = 0;
    scanf("%d", &v); //찾는값 입력
    int cnt = 0; // v와 같은 값 개수
    for(int i = 0 ; i<N;i++){ //같은값 찾기
        if(a[i] == v)
            cnt++;
    }
    printf("%d",cnt);
    return 0;
}
