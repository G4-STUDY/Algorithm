//백준 10026 적록색약
#include<bits/stdc++.h>
using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int N;
int num_area1, num_area2;
vector<string> board;
bool vis[102][102]; //방문 여부 배열

//입력 좌표 기준, 인접한 같은 색깔 칸 방문 처리(vis 배열) 
void bfs(int, int);
//영역의 수 반환
int cal_NumArea(void);


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int i;
    string s;

    cin >> N;
    for(i = 0; i < N; i++ ){
        cin >> s;
        board.push_back(s);
    }

    num_area1 = cal_NumArea();
    //vis배열 초기화, 적록 색맹 board 처리
    memset(vis, 0, sizeof(vis));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < board[0].size(); j++){
            if(board[i][j] == 'R') board[i][j] = 'G';
        }
    }
    num_area2 = cal_NumArea(); 

    cout << num_area1 << ' ' << num_area2;

    return 0;
}

void bfs(int i, int j){
    int dir, nx, ny;
    char cur_color = board[i][j]; //시작점의 색깔
    queue<pair<int,int>> q; 
    q.push({i,j});
    vis[i][j] = true;

    while(!q.empty()){
        pair<int, int> cur = q.front(); q.pop();
        for(dir = 0; dir < 4; dir++){
            nx = cur.first + dx[dir];
            ny = cur.second + dy[dir];
            if(nx < 0|| ny < 0|| nx >= N|| ny >= board[0].size()) continue;
            if(vis[nx][ny] == true|| board[nx][ny] != cur_color) continue;
            q.push({nx, ny});
            vis[nx][ny] = true; //방문하지 않고, 시작점과 같은 색깔인 칸 방문 표시
        }
    }
}

int cal_NumArea(void){
    int num_area = 0;
    int i,j;
    for(i = 0; i < N; i++){
        for(j = 0; j < board[0].size(); j++){
            if(vis[i][j] == true) continue;
            //(i, j)를 시작점으로 같은 색깔 영역 방문 처리
            bfs(i,j);
            num_area++;
        }
    }
    return num_area;
}

/*
1. R,G,B 모두 다른 색깔
2. R==G , B 로 처리 
board 2 개 만들기?
 
*/