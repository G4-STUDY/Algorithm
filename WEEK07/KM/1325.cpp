#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int n,m;
vector<int> edge[10001];
int mx;
int ans[10001];
int idx,cnt;
bool visit[10001];

void dfs(int cur){
    for(int next:edge[cur]){
        if(visit[next]) continue;
        cnt++;
        visit[next]=true;
        dfs(next);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        edge[b].push_back(a);//단방향
    }
    idx=0;mx=0;//정답개수,최대값
    for(int i=1;i<=n;i++){
        memset(visit,false,sizeof(visit));
        visit[i]=true;
        cnt=1;//해킹할수있는 컴퓨터수
        dfs(i);
        if(cnt>=mx){//정답보다 크거나 같으면
            if(mx==cnt){//같을땐 배열에 추가
                ans[idx]=i;
                idx++;
            }
            else{//크면 갱신
                mx=cnt;
                ans[0]=i;
                idx=1;
            }
        }
    }
    for(int i=0;i<idx;i++){
        cout<<ans[i]<<' ';
    }
    return 0;
}