//백준2583 영역 구하기
#include<bits/stdc++.h>
using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int board[102][102]; // y, x
bool vis[102][102];
vector<int> areas; //영역의 넓이 저장
int M,N; //모눈종이 크기
int K; //그리는 직사각형 수
int num_area = 0; //영역의 수
void fillData(int, int, int, int);
int bfs(int, int);

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int i,j;
    int x1, y1, x2, y2;
    int cur_area; 
    cin >> M >> N >> K;
    //직사각형 그리기
    for(i = 0; i < K; i++){
        cin >> x1 >> y1 >> x2 >> y2;
        fillData(x1, y1, x2, y2);
    }


    //bfs 처리
    for(i = 0; i < M ;i++){
        for(j = 0; j < N; j++){
            //방문되지 않은, 값이 0인 좌표를 시작점으로 bfs
            if((board[i][j] == 1) || (vis[i][j] == true)) continue;
            num_area ++;
            //현재 시작점에 대한 영역의 넓이
            cur_area = bfs(i, j);
            areas.push_back(cur_area);
        }
    }
    //출력
    sort(areas.begin(), areas.end());
    cout << num_area << '\n';
    for(i =0; i < num_area; i++){
        cout << areas[i] << ' ';
    }
}
//board는 칸의 왼쪽 아래 좌표 기준
void fillData(int x1, int y1, int x2, int y2){
    int i,j;
    for(i = x1; i <= (x2 - 1); i++){
        for(j = y1; j <= (y2 - 1); j++){
            //겹치는 부분 덮어씌우기
            board[j][i] = 1;
        }
    }
}

int bfs(int cur_x, int cur_y){
    int siz = 0;
    int dir, nx, ny;
    queue<pair<int,int>> q;
    q.push({cur_x, cur_y});
    vis[cur_x][cur_y] = true;
    siz++;
    while(!q.empty()){
        pair<int, int> cur = q.front(); q.pop();
        for(dir = 0; dir < 4 ; dir++){
            nx = cur.first + dx[dir];
            ny = cur.second +dy[dir];
            if((nx < 0)|| (ny < 0)|| (nx >= M)|| (ny >= N)) continue;
            if((vis[nx][ny] == true)|| (board[nx][ny] == 1)) continue;
            //시작점 cur_x, cur_y 주변 좌표 중 방문되지 않은, 값이 0인 좌표
            q.push({nx, ny});
            vis[nx][ny] = true;
            siz++;
        }
    }
    return siz;
}