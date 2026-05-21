#include <iostream>
using namespace std;

//queue를 통한 BFS 구현
typedef struct {
    int z;
    int x;
    int y;
    int cout; // 날짜  
} NODE;

int m, n, h;
int map[101][101][101];

NODE queue [101 * 101 * 101]; // 최악의 수 가정
int front = 0, rear = 0;

//queue 구현
bool itsEmpty() {
    return front == rear; // 전역변수
}

void enq(int z, int x, int y, int c) {
    NODE temp = {z, x, y, c};
    queue[rear++] = temp; // 후위연산자이용
}

NODE deq() {
    return queue[front++]; // 후위연산자
}

int ans = 0;
int cnt = 0;

int dx[6] = { 1, -1, 0, 0, 0, 0 };
int dy[6] = { 0, 0, 1, -1, 0, 0 };
int dz[6] = { 0, 0, 0, 0, 1, -1 };

void BFS() {
    while(!itsEmpty()) { // Queue가 빌 때까지 
        NODE temp = deq();

        ans = temp.cout > ans ? temp.cout : ans;

        for(int i = 0; i < 6; i++) {
            int nz = temp.z + dz[i];
            int nx = temp.x + dx[i];
            int ny = temp.y + dy[i];

            if(nx < 0 || ny < 0 || nz < 0) 
                continue; // 벗어 났을때
            if(nx >= n || ny >= m || nz >= h)
                continue; // 벗어 났을때

            if(map[nz][nx][ny] == 0) {
                map[nz][nx][ny] = temp.cout + 1;
                cnt ++;
                enq(nz, nx, ny, temp.cout + 1);
            }
        }

    }
}

int main(){
    cin >> m >> n >> h;
    int compare = m * n * h;


    for(int z = 0; z < h; z++){

        for(int x = 0; x < n; x++){

            for (int y = 0; y < m; y++){

                cin >> map[z][x][y];

                if(map[z][x][y] == 1){
                    enq(z, x, y, 1);
                    cnt ++;
                }

                if(map[z][x][y] == -1){
                    compare --;
                }

            }
        }
    }

    BFS();

    if(cnt == compare){
        cout << ans - 1 << endl;
    } else {
        cout << "-1" << endl;
    }

    return 0;
}