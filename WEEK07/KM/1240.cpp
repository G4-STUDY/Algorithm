#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

vector<pair<int,int>> edge[1001];
bool visit[1001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<n;i++){
        int a,b,c;
        cin>>a>>b>>c;
        edge[a].push_back({b,c});
        edge[b].push_back({a,c});
    }
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        memset(visit,false,sizeof(visit));
        queue<pair<int,int>> q; //노드,거리
        visit[a]=true;
        q.push({a,0});
        bool flag=true;
        //bfs
        while(!q.empty()&&flag){
            int cur=q.front().first;
            int dist=q.front().second;
            q.pop();
            for(pair<int,int> tmp:edge[cur]){
                int next=tmp.first;
                if(visit[next])continue;
                visit[next]=true;
                int ndist=dist+tmp.second;
                if(next==b) // b까지 갔으면 종료
                {
                    flag=false;
                    cout<<ndist<<'\n';
                }
                q.push({next,ndist});
            }
        }
    }
    return 0;
}
/*
플로이드 되냐?
시간초과
트리임..
bfs ㄱㄱ..
*/