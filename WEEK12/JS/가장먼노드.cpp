#include <string>
#include <vector>
#include <queue>
using namespace std;
const int INF = 0x3fffffff;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    vector<pair<int, int>> adj[20001]; //{dist, adj node} index 1 부터 
    int max_dist = 1; 
    
    for(vector<int> e : edge)
    {
        adj[e[0]].push_back({1,e[1]});
        adj[e[1]].push_back({1,e[0]});
    }
    
    //dijkstra for node 1
    priority_queue <pair<int, int>, 
                    vector<pair<int, int>>,
                    greater<pair<int, int>>> pq; //{dist, node}
    int dist[20001];
    for(int i = 1; i <= n; i++)
    {
        dist[i] = INF;
    }
    dist[1] = 0;
    
    pq.push({0, 1});
    while(!pq.empty())
    {
        pair<int, int> cur = pq.top(); pq.pop();
        int cur_dist = cur.first; int cur_node = cur.second;
        if(dist[cur_node] != cur_dist) continue;
        for(pair<int, int> nxt : adj[cur_node])
        {
            int nxt_dist = nxt.first; int nxt_node = nxt.second;
            if(dist[nxt_node] > dist[cur_node] + nxt_dist)
            {
                dist[nxt_node] = dist[cur_node] + nxt_dist;
                max_dist = max(max_dist, dist[nxt_node]);
                pq.push({dist[nxt_node], nxt_node});
            }
        }
    }
    for(int i = 2; i <= n; i++)
    {
        if(dist[i] == max_dist) answer++;
    }
    return answer;
}

//BFS로 다시 풀어보기 