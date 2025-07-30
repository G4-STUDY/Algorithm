#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int n;
vector<int> edge[51];
vector<int> ans[51];
int answer=50;
bool visit[51];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n;
    int a,b;
    while(1){
        cin>>a>>b;
        if(a==-1&&b==-1) break;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    for(int i=1;i<=n;i++){
        memset(visit,false,sizeof(visit));
        visit[i]=true;
        int cnt=1;//친구인 회원수
        bool flag=true;
        //bfs
        queue<pair<int,int>> q;
        q.push({i,0});
        while(!q.empty()&&flag){
            int cur=q.front().first;
            int score=q.front().second;
            q.pop();
            for(int next:edge[cur]){
                if(visit[next]) continue;
                visit[next]=true;
                cnt++;
                q.push({next,score+1});
            }
            if(cnt==n){//전부 친구 됐으면
                flag=false;
                if(answer>=score+1){//정답 갱신
                    answer=score+1;
                    ans[answer].push_back(i);
                }
            }
        }
    }


    cout<<answer<<' '<<ans[answer].size()<<'\n';
    for(int x:ans[answer]){
        cout<<x<<' ';
    }
    return 0;
}