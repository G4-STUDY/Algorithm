#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
using namespace std;



#define X first
#define Y second // pair에서 first, second를 줄여서 쓰기 위해서 사용
int board[102][102]; // 1이 파란 칸, 0이 빨간 칸에 대응
bool vis[102][102]; // 해당 칸을 방문했는지 여부를 저장
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 }; // 상하좌우 네 방향을 의미


int main(void) {
    int N, M, K; // n = 행의 수, m = 열의 수
    cin >> M >> N >> K;
    int x_start, y_start, x_end, y_end;
    
    for (int i = 0; i < K; i++) {
        cin >> x_start >> y_start >> x_end >> y_end;
        for (int u = x_start; u < x_end; u++) {
            for (int v = y_start; v < y_end; v++) {
                board[u][v] = 1;
            }
        }
    }


    int area = 0;
    int area_ary[100];
    int cnt = 0;
    queue<pair<int, int> > Q;
    for (int u = 0; u < N; u++) {
        for (int v = 0; v < M; v++) {
            if (!board[u][v] && !vis[u][v]) {
                vis[u][v] = 1; // (0, 0)을 방문했다고 명시
                cnt++;
                Q.push({ u,v }); // 큐에 시작점인 (0, 0)을 삽입.
                while (!Q.empty()) {
                    pair<int, int> cur = Q.front(); Q.pop();
                    area++;
                    for (int dir = 0; dir < 4; dir++) { // 상하좌우 칸을 살펴볼 것이다.
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir]; // nx, ny에 dir에서 정한 방향의 인접한 칸의 좌표가 들어감
                        if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue; // 범위 밖일 경우 넘어감
                        if (vis[nx][ny] || board[nx][ny] == 1) continue; // 이미 방문한 칸이거나 파란 칸이 아닐 경우
                        vis[nx][ny] = 1; // (nx, ny)를 방문했다고 명시
                        Q.push({ nx,ny });
                    }
                }
                area_ary[cnt-1] = area;
                area = 0;
            }
        }
    }
    cout << cnt << '\n';
    sort(area_ary, area_ary + cnt);
    for (int i = 0; i < cnt; i++) {
        cout << area_ary[i] << " ";
    }
}
