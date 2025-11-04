#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n,m;
int a,b,c;
vector<pair<int,int>> edge[100001];
int s,e;
priority_queue<pair<int,int>>pq;
int dist[100001];

int main()
{
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>a>>b>>c;
        edge[a].push_back({b,c});
        edge[b].push_back({a,c});
    }
    cin>>s>>e;
    pq.push({1e9,s});
    while(!pq.empty()){
        int cur=pq.top().second;
        int w=pq.top().first;
        pq.pop();
        if(dist[cur]>=w)continue;
        dist[cur]=w;
        for(pair<int,int> nextp:edge[cur]){
            int next=nextp.first;
            int nw=min(w,nextp.second);
            if(dist[next]<nw){
                pq.push({nw,next});
            }
        }
    }
    cout<<dist[e];
    return 0;
}