#include <iostream>
#include <vector>
using namespace std;
const int INF = 1e9;
int tc;
int n, m, w;
int dist[501];
bool visit[501];
vector<pair<pair<int, int>, int>> edge;

void initialize()
{
    for (int i = 1; i <= n; i++)
    {
        dist[i] = INF;
    }
}

bool bellmanford(int start)
{
    dist[start] = 0;
    for (int i = 0; i < n - 1; i++) // n-1번
    {
        for (pair<pair<int, int>, int> e : edge)
        {
            int cur = e.first.first;
            int next = e.first.second;
            int cost = e.second;
            if (dist[cur] == INF)
                continue;
            if (dist[next] > dist[cur] + cost)
            {
                dist[next] = dist[cur] + cost;
            }
        }
    }
    // 음의 사이클 확인
    for (pair<pair<int, int>, int> e : edge)
    {
        int cur = e.first.first;
        int next = e.first.second;
        int cost = e.second;
        if (dist[cur] == INF)
            continue;
        if (dist[next] > dist[cur] + cost)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> tc;
    while (tc--)
    {
        cin >> n >> m >> w;
        int s, e, t;
        edge.clear();
        for (int i = 0; i < m; i++)
        {
            cin >> s >> e >> t;
            edge.push_back({{s, e}, t});
            edge.push_back({{e, s}, t});
        }
        for (int i = 0; i < w; i++)
        {
            cin >> s >> e >> t;
            edge.push_back({{s, e}, -t});
        }
        bool flag = true;
        for (int i = 1; i <= n; i++)
        {
            visit[i] = false;
        }
        for (int i = 1; i <= n; i++)
        {
            initialize();
            if (visit[i])
                continue;
            if (!bellmanford(i)) // 음의 사이클이 있으면
            {
                flag = false;
                break;
            }
            for (int j = 1; j <= n; j++)
            {
                if (dist[j] != INF)
                {
                    visit[j] = true;
                }
            }
        }
        if (flag)
            cout << "NO\n";
        else
            cout << "YES\n";
    }
    return 0;
}
/*
모든 도시는 연결되어잇나? X
시간 더줄일려면 도로 중복 제거도 해주자
*/
/*
도로중복 제거
더 오래걸림.. 중복이 몇개없는듯..
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
const int INF =1e9;
int tc;
int n,m,w;
int dist[501];
bool visit[501];
int edgecost[501][501];
bool edgecheck[501][501];
vector<pair<int,int>> edge;

void initialize(){
    for(int i=1;i<=n;i++){
        dist[i]=INF;
    }
}

bool bellmanford(int start){
    dist[start]=0;
    for(int i=0;i<n-1;i++){
        for(pair<int,int> e:edge){
            int cur=e.first;
            int next=e.second;
            int cost=edgecost[cur][next];
            if(dist[cur]==INF)continue;
            if(dist[next]>dist[cur]+cost){
                dist[next]=dist[cur]+cost;
            }
        }
    }
    for(pair<int,int> e:edge){
        int cur=e.first;
        int next=e.second;
        int cost=edgecost[cur][next];
        if(dist[cur]==INF)continue;
        if(dist[next]>dist[cur]+cost){
            return false;
        }
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>tc;
    while(tc--){
        cin>>n>>m>>w;
        int s,e,t;
        edge.clear();
        memset(edgecheck,false,sizeof(edgecheck));
        for(int i=0;i<m;i++){
            cin>>s>>e>>t;
            if(edgecheck[s][e]){
                t=min(edgecost[s][e],t);
            }
            else{
                edge.push_back({s,e});
                edge.push_back({e,s});
                edgecheck[s][e]=true;
                edgecheck[e][s]=true;
            }
            edgecost[s][e]=t;
            edgecost[e][s]=t;
        }
        for(int i=0;i<w;i++){
            cin>>s>>e>>t;
            t=-t;
            if(edgecheck[s][e]){
                t=min(edgecost[s][e],t);
            }
            else{
                edge.push_back({s,e});
                edgecheck[s][e]=true;
            }
            edgecost[s][e]=t;
        }
        bool flag=true;
        for(int i=1;i<=n;i++){
            visit[i]=false;
        }
        for(int i=1;i<=n;i++){//방문안된 노드들에서도 돌려봐야댐
            initialize();
            if(visit[i]) continue; //안하면 시간초과
            if(!bellmanford(i)){
                flag=false;
                break;
            }
            for(int j=1;j<=n;j++){
                if(dist[j]!=INF){
                    visit[j]=true;
                }
            }
        }
        if(flag)cout<<"NO\n";
        else cout<<"YES\n";
    }
    return 0;
}
*/