#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N; 
    cin >> N;
    vector<int> adj[100001];
    int parent[100001] = { 0, }; // 루트의 부모는 0
    for(int i = 0; i < N - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); 
    }

    //노드 1을 시작점으로 bfs
    queue<int> q;
    q.push(1);
    while(!q.empty())
    {
        int cur = q.front(); q.pop();
        for(int nxt : adj[cur])
        {
            if(nxt == parent[cur]) continue;
            q.push(nxt);
            parent[nxt] = cur;
        }
    }

    for(int node = 2; node <= N; node++ )
    {
        cout << parent[node] << '\n';
    }
    return 0;

}