//특정한 최단 경로
//틀린 이유-> INF 값 설정
#include<iostream>
#include<vector>
#include<queue>
#define DIST first
#define NODE second
using namespace std;
const int INF = 300000000;
vector<pair<int, int>> graph[801]; //인덱스 1부터
int n, e;
//st에서 en까지 최단 거리 반환
int  dijkstra(int st, int en)
{
    int dist[801]; //dist[i] : st에서 i 최단 거리 
    priority_queue<pair<int, int>,
                    vector<pair<int, int>>,
                    greater<pair<int, int>>> pq; // 비용, 정점 번호
    fill(dist, dist + 801, INF);
    dist[st] = 0;
    pq.push({0, st});
    while(!pq.empty())
    {
        pair<int, int> cur = pq.top(); pq.pop();
        if(dist[cur.NODE] != cur.DIST) continue;
        //cur 과 인접한 정점 확인 
        for(pair<int, int> nxt : graph[cur.NODE])
        {
            int temp_dist = nxt.DIST + dist[cur.NODE]; //st에서 nxt까지 최단거리 후보 = cur에서 nxt 거리 + st에서 cur 최단거리
            if(temp_dist < dist[nxt.NODE])
            {
                dist[nxt.NODE] = temp_dist;
                pq.push({temp_dist,nxt.NODE});
            }
        }
        
    }

    return dist[en]; //st 에서 en 까지의 최단 거리 
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    
    cin >> n >> e;
    while(e--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({c,b});
        graph[b].push_back({c,a});
    }
    int u, v;
    cin >> u >> v;
    int u_to_v = dijkstra(1, u) + dijkstra(u, v) + dijkstra(v, n);
    int v_to_u = dijkstra(1, v) + dijkstra(v, u) + dijkstra(u, n);
    //3개의 항 중 한개라도 INF가 존재하면 false(경로 없음)
    if(u_to_v >= INF && v_to_u >= INF) cout << -1;
    else cout << min(u_to_v, v_to_u);

   

    return 0;
}

/*
u!=v, u!=1, u!=n

case1)
1-u-v-n

case2)
1-v-u-n


int dijkstra(int st,int en)
*/