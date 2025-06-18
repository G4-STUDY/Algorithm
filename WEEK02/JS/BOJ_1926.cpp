//백준1926 그림
#include<bits/stdc++.h>
using namespace std;

int dx[4] = {1,-1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int board[502][502]; //그림 상태 
bool vis[502][502]; //bfs 방문 여부
int n, m; //가로,세로 크기
int num_picture, mx_size; //그림 수, 최대 그림 넓이
int bfs(int, int); //bfs 함수, 현재 시작점에 대한 그림 넓이 반환

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int i, j;
    int cur_size = 0;
    //입력 
    cin >> n >> m;
    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            cin >> board[i][j];
        }
    }

    //bfs 시작점 찾고, bfs 처리
    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            if((board[i][j] == 0) || (vis[i][j] == true) ) continue;
            //(i, j)를 시작점으로 bfs 처리, 그림수 증가
            num_picture++;
            cur_size = bfs(i, j);
            mx_size = max(mx_size, cur_size);
        }
    }

    cout << num_picture << '\n' << mx_size;
    return 0;
}

int bfs(int cur_n, int cur_m){
    queue<pair<int, int>> q;
    int dir, nx, ny;
    int siz = 0;

    q.push({cur_n, cur_m});
    vis[cur_n][cur_m] = true;
    siz++; //시작점도 넓이에 포함

    while(!q.empty()){
        pair<int, int> cur = q.front(); q.pop();
        for(dir = 0; dir < 4; dir++){
            nx = cur.first + dx[dir];
            ny = cur.second + dy[dir];
            //pop 좌표의 주변 좌표 중 방문되지 않은, 0인 칸만 방문
            if((nx < 0)|| (ny < 0)|| (nx >= n)|| (ny >= m)) continue;
            if((vis[nx][ny] == true)|| (board[nx][ny] == 0)) continue;
            //방문 가능 좌표 
            q.push({nx, ny});
            vis[nx][ny] = true;
            siz++;
        }
    }
    return siz;

}