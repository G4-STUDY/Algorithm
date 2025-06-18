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
char board[102][102];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 }; // 상하좌우 네 방향을 의미

int see_R_G_B(char a, int n);
int see_RG_B(int n);

int see_R_G_B(char a, int n) {
    int cnt = 0;
    bool vis[102][102] = { 0 };
    queue<pair<int, int> > Q;
    for (int u = 0; u < n; u++) {
        for (int v = 0; v < n; v++) {
            if ((board[u][v] == a) && !vis[u][v]) {
                vis[u][v] = 1; // (0, 0)을 방문했다고 명시
                cnt++;
                Q.push({ u,v }); // 큐에 시작점인 (0, 0)을 삽입.
                while (!Q.empty()) {
                    pair<int, int> cur = Q.front(); Q.pop();
                    for (int dir = 0; dir < 4; dir++) { // 상하좌우 칸을 살펴볼 것이다.
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir]; // nx, ny에 dir에서 정한 방향의 인접한 칸의 좌표가 들어감
                        if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue; // 범위 밖일 경우 넘어감
                        if (vis[nx][ny] || board[nx][ny] != a) continue; // 이미 방문한 칸이거나 파란 칸이 아닐 경우
                        vis[nx][ny] = 1; // (nx, ny)를 방문했다고 명시
                        Q.push({ nx,ny });
                    }
                }
            }
        }
    }
    return cnt;
}

int see_RG_B(int n) {
    int cnt = 0;
    bool vis[102][102] = { 0 };
    queue<pair<int, int> > Q;
    for (int u = 0; u < n; u++) {
        for (int v = 0; v < n; v++) {
            if ((board[u][v] != 'B') && !vis[u][v]) {
                vis[u][v] = 1; // (0, 0)을 방문했다고 명시
                cnt++;
                Q.push({ u,v }); // 큐에 시작점인 (0, 0)을 삽입.
                while (!Q.empty()) {
                    pair<int, int> cur = Q.front(); Q.pop();
                    for (int dir = 0; dir < 4; dir++) { // 상하좌우 칸을 살펴볼 것이다.
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir]; // nx, ny에 dir에서 정한 방향의 인접한 칸의 좌표가 들어감
                        if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue; // 범위 밖일 경우 넘어감
                        if (vis[nx][ny] || board[nx][ny] == 'B') continue; // 이미 방문한 칸이거나 파란 칸이 아닐 경우
                        vis[nx][ny] = 1; // (nx, ny)를 방문했다고 명시
                        Q.push({ nx,ny });
                    }
                }
            }
        }
    }
    return cnt;
}

int main(void) {
    int N;
    cin >> N;
    char color;

    for (int u = 0; u < N; u++) {
        for (int v = 0; v < N; v++) {
            cin >> color;
            board[u][v] = color;
        }
    }
    int R_G_B = see_R_G_B('R', N) + see_R_G_B('G', N) + see_R_G_B('B', N);
    int RG_B = see_RG_B(N) + see_R_G_B('B', N);
    cout << R_G_B << '\n' << RG_B;
}
