//면접보는 승범이네 
#include<iostream>
#include<vector>
#include<queue>
#define DIST first
#define NODE second
using namespace std;
const int INF = 0x7fffffff;
int n, m, k;
vector<pair<int, int>> graph[100001]; //인덱스 1부터 
vector<int> job_interview_places;

int dijkstra(int st, int en){
    //initial setting 
    vector<int> dist(n + 1); // 1 ~ n
    fill(dist.begin(), dist.end(), INF);
    dist[st] = 0;
    priority_queue<pair<int, int>,
                   vector<pair<int, int>>,
                   greater<pair<int, int>>> pq; //min heap
    //start
    pq.push({0, st});
    while(!pq.empty())
    {
        pair<int, int> cur = pq.top(); pq.pop();
        if(dist[cur.NODE] != cur.DIST) continue; //유효하지 않은 pq 원소
        for(pair<int, int> nxt : graph[cur.NODE] )
        {
            int temp_nxt_dist = dist[cur.NODE] + nxt.DIST; //st에서 nxt까지 최단 거리 후보 = st->cur + cur->nxt
            if(temp_nxt_dist < dist[nxt.NODE])
            {
                dist[nxt.NODE] = temp_nxt_dist; //dist[nxt] 갱신
                pq.push({temp_nxt_dist, nxt.NODE});
            }
        }
    }

    return dist[en];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;
    for(int i = 0; i < m; i++)
    {
        int u, v, c;
        cin >> u >> v >> c;
        graph[u].push_back({c, v});
    }

    for(int i = 0; i < k; i++)
    {
        int j;
        cin >> j;
        job_interview_places.push_back(j);
    }

    /*
    find minimum 
    */

}

/*
정점 n 개 
n개 중 면접장 k 개 
elogv 
500000*log100000 = 10^7

*/