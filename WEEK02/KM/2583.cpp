#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int m,n,k;
bool arr[101][101];
bool visit[101][101];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
vector<int> ans;
int tmp=0;
void my_fill(int lx,int rx,int ly,int ry){ // 왼쪽아래좌표,오른쪽아래좌표 까지 네모 채우기
    for(int i=lx;i<rx;i++)
    {
        for(int j=ly;j<ry;j++)
        {
            arr[i][j]=1;
        }
    }
}

void dfs(int x,int y)
{
    visit[x][y]=true;   //방문처리
    tmp++;              //넓이++
    for(int i=0;i<4;i++)
    {
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(0<=nx&&nx<n&&0<=ny&&ny<m)//범위체크
        {
            if(!arr[nx][ny]&&!visit[nx][ny])//방문체크,갈수잇는지체크
            {
                dfs(nx,ny);
            }
        }
    }
}

int main()
{
    cin>>m>>n>>k;
    for(int i=0;i<k;i++)
    {
        int lx,rx,ly,ry;
        cin>>lx>>ly>>rx>>ry;
        my_fill(lx,rx,ly,ry);//네모 칠하기
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
        {
            if(arr[i][j]||visit[i][j])continue;//방문가능한지
            tmp=0;  //넓이 초기화
            dfs(i,j);   //탐색
            ans.push_back(tmp);//넓이 넣기
        }
    }
    sort(ans.begin(),ans.end());    //넓이정렬
    cout<<ans.size()<<'\n';//영역 개수
    for(int answer:ans) //출력
        cout<<answer<<' ';
    return 0;
}