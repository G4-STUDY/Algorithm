#include<iostream>
#include<queue>
#include<vector>
using namespace std;


vector<pair<int,int>> graph[20000]; //graph[i]:정점 i의 인접 정점 w에대해 {거리, w} 저장 
int dist[20001]; // 시작 정점과의 거리

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    const int INF = 0x7fffffff;
    priority_queue<pair<int,int>, 
        vector<pair<int, int>>,
        greater<pair<int,int>>> pq; //최소 힙  

    int v, e; //정점 수, 간선 수
    cin >> v >> e;
    int k; //시작 정점 번호
    cin >> k; 
    while(e--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({w,v});  
    } 

    fill(dist, dist + 20001, INF);
    
    dist[k] = 0;
    pq.push({0,k});
    while (!pq.empty())
    {
        pair<int, int> cur_pair = pq.top(); pq.pop();
        int cur_cost = cur_pair.first; //정점 k에서 정점 cur_node까지의 최단 거리
        int cur_node = cur_pair.second;
        if(dist[cur_node] != cur_cost) continue; //이미 갱신된 노드에 대한 원소 pass
        for(auto nxt : graph[cur_node]){
            
            int temp_nxt_cost = cur_cost + nxt.first; //정점 k에서 정점 nxt까지 최단 거리 후보(k에서 cur_node + cur_node에서 nxt)
            if(dist[nxt.second] > temp_nxt_cost)
            {
                dist[nxt.second] = temp_nxt_cost; ////정점 k에서 정점 nxt까지 최단 거리 갱신
                pq.push({temp_nxt_cost, nxt.second});
            }
        }
    }

    for(int i = 1; i <=  v; i++){
        if(dist[i] == INF) cout << "INF" <<'\n';
        else cout << dist[i] << '\n';
    }


    
}