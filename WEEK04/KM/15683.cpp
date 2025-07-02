#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int n, m;
int tmp[10][10];
int arr[10][10];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
vector<int> cctv[6];
/*
cctv    dx,dy
1       0
2       0,2
3       0,1
4       0,1,2
5       0,1,2,3
*/
vector<pair<int, int>> v; //cctv 있는 위치
vector<int> vdir; //cctv 가 어느방향으로 돌아가있는지 0~3
int mn;

void dfs(int x,int y,int dir){ //방향으로 직진
    int nx=x+dx[dir];
    int ny=y+dy[dir];
    if(nx<=0||nx>n||ny<=0||ny>m){
        return;
    }
    if(tmp[nx][ny]==6){//벽이면
        return;
    }
    if(tmp[nx][ny]==0){//빈칸이면
        tmp[nx][ny]=-1;
        dfs(nx,ny,dir);
    }
    else{//이미 감시중 or cctv
        dfs(nx,ny,dir);
    }
}

void calc()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            tmp[i][j] = arr[i][j]; //tmp배열 초기화
        }
    }
    for(int i=0;i<v.size();i++){//cctv 하나씩
        int curx=v[i].first;    //cctv x
        int cury=v[i].second;   //cctv y
        int curcctv=arr[curx][cury]; //cctv종류
        for(int ddir:cctv[curcctv]){//현재종류 cctv 발사
            dfs(curx,cury,(vdir[i]+ddir)%4); 
            //             어느방향으로 가야돼?
            //             돌아있는만큼 돌리고 발사
        }
    }
    //printtmp();
    int num=0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if(tmp[i][j]==0){
                num++;
            }
        }
    }
    mn=min(mn,num);
}

void backtrack(int cnt)
{
    if (cnt == v.size())
    {
        calc();
        return;
    }
    int x = v[cnt].first;
    int y = v[cnt].second;
    int cur = arr[x][y];
    if (cur == 1 || cur == 3 || cur == 4)
    {   //4방향으로 돌려야되는 애들
        for (int i = 0; i < 4; i++)
        {
            vdir[cnt] = i;
            backtrack(cnt + 1);
        }
    }
    else if (cur == 2)//얘는 두방향으로 돌리면됌
    {
        vdir[cnt] = 0;
        backtrack(cnt + 1);
        vdir[cnt] = 1;
        backtrack(cnt + 1);
    }
    else
    {   //얘는 안돌려도됨..
        backtrack(cnt + 1);
    }
}

int main()
{
    cin >> n >> m;
    mn = m * n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] > 0 && arr[i][j] < 6)
            {
                v.push_back({i, j});
                vdir.push_back({1});
            }
        }
    }
    /*
    1       0
2       0,2
3       0,1
4       0,1,2
5       0,1,2,3
    */
    cctv[1].push_back(0);
    cctv[2].push_back(0);
    cctv[2].push_back(2);
    cctv[3].push_back(0);
    cctv[3].push_back(1);
    cctv[4].push_back(0);
    cctv[4].push_back(1);
    cctv[4].push_back(2);
    cctv[5].push_back(0);
    cctv[5].push_back(1);
    cctv[5].push_back(2);
    cctv[5].push_back(3);
    backtrack(0);
    cout << mn;
    return 0;
}
// 4^8 = 2^16= 1024*64= 6500 경우의수
//  전부 돌려보기 4방향으로 백트래킹
/*

5번은 돌릴필요없음

*/