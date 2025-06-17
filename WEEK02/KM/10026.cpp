#include <iostream>
#include <cstring>
using namespace std;
int n;
char arr[101][101];     //그림배열
int visit[101][101];    //방문처리배열
int dx[4]={1,-1,0,0};   
int dy[4]={0,0,1,-1};

void dfs(int x,int y)
{
    visit[x][y]=true;   //방문처리
    for(int i=0;i<4;i++)
    {
        int nx=x+dx[i]; //다음점
        int ny=y+dy[i];
        if(0<=nx&&nx<n&&0<=ny&&ny<n)//범위체크
        {
            if(!visit[nx][ny]&&arr[nx][ny]==arr[x][y])
            {   //가도돼?
                dfs(nx,ny);
            }
        }
    }
}

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>arr[i][j]; 
        }
    }
    int cnt=0;//구역 0개초기화
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(visit[i][j]) continue;   //이미방문했으면
            dfs(i,j);   
            cnt++;//구역++
        }
    }
    cout<<cnt<<' ';//출력
    memset(visit,false,sizeof(visit));//방문배열 초기화
    cnt=0;//구역 0개로 초기화
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(arr[i][j]=='G')//G를 R로 바꾸기 || R을 G로 바꾸기
                arr[i][j]='R';
        }
    }
    for(int i=0;i<n;i++)//위의 탐색과동일
    {
        for(int j=0;j<n;j++)
        {
            if(visit[i][j]) continue;
            dfs(i,j);   
            cnt++;
        }
    }
    cout<<cnt<<' ';//출력
    return 0;
}