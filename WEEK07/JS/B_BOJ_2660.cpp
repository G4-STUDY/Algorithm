#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<unordered_map>
using namespace std;
//node에 대해 최대 거리 반환 
int bfs(int node, vector<int> adj[])
{
    int dist[51];
    int max_dist = -1;
    fill(dist, dist + 51, -1);
    queue<int> q;
    q.push(node);
    dist[node] = 0;
    while(!q.empty())
    {
        int cur = q.front(); q.pop();
        for(int nxt : adj[cur])
        {
            if(dist[nxt] != -1) continue;
            q.push(nxt);
            dist[nxt] = dist[cur] + 1;
            max_dist = max(max_dist, dist[nxt]);
        }
    }
    return max_dist; //score 
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> adj[51];
    
    int N; 
    cin >> N;
    //그래프 생성
    while(1)
    {
        int u, v;
        cin >> u >> v;
        if(u == -1 && v == -1) break;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    unordered_map<int,int> node_score_map; // (노드 번호,점수) 저장 맵
    int min_score = 0x7fffffff; //
    for(int node = 1; node <= N; node++)
    {
        int score = bfs(node, adj);
        node_score_map[node] = score;
        min_score = min(min_score, score);
    }

    vector<int> candidate; // 후보자 노드 번호 저장 벡터 
    for(int node = 1; node <= N; node++)
    {
        if(node_score_map[node] == min_score)
        {
            candidate.push_back(node);
        }
    }
    //후보자 노드 번호 오름 차순 정렬 
    sort(candidate.begin(), candidate.end());

    //출력
    cout << min_score << ' ' << candidate.size() << '\n';
    for(int node : candidate)
    {
        cout << node << ' ';
    }
    return 0;

}





    


