#include <iostream>

using namespace std;

int n,m;
int ans=0,tmp=0;
int cnt=0;
bool arr[501][501];
bool visit[501][501];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};


void dfs(int x,int y)
{
    visit[x][y]=true; //방문처리
    tmp++;  //넓이 증가
    for(int i=0;i<4;i++){//4방향 탐색
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(0<=nx&&nx<n&&0<=ny&&ny<m)//범위안이면
            if(arr[nx][ny]&&!visit[nx][ny])//그림이야?이미방문?
            {
                dfs(nx,ny);//탐색
            }
    }
}

int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!arr[i][j]||visit[i][j])continue; //그림이없거나 방문했으면
            cnt++;
            tmp=0;//넓이 0 초기화
            dfs(i,j);// 연결된부분 방문,넓이 더하기
            ans=max(ans,tmp);//넓이 비교
        }
    }
    cout<<cnt<<"\n";//개수
    cout<<ans;//가장큰 그림의 넓이
    return 0;
}