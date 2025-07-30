#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b)
{
    if(a.second != b.second)
        return a.second < b.second;
    else    
        return a.first > b.first;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<pair<int,int>> node_number_vector;
    int n, m;
    cin >> n >> m;
    vector<int> adj[10001];
    
    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[v].push_back(u);
    }
    //각 노드에 대해 시작점으로 bfs 수행
    for(int i = 1; i <= n; i++)
    {
        int visit_number = 0;
        int vis[10001] = { 0,};
        queue<int> q;
        q.push(i);
        vis[i] = 1;
        visit_number += 1;
        while(!q.empty())
        {
            int cur = q.front(); q.pop();
            for(int nxt : adj[cur])
            {
                if(vis[nxt] == 1) continue;
                q.push(nxt);
                vis[nxt] = 1;
                visit_number += 1;
            }
        }
    pair<int, int> node_info;
    node_info.first = i;
    node_info.second = visit_number;
    node_number_vector.push_back(node_info);

    }

    sort(node_number_vector.begin(), node_number_vector.end(),cmp);
    int maximum_number = node_number_vector.back().second;
    while(node_number_vector.back().second == maximum_number )
    {
        cout << node_number_vector.back().first << ' ';
        node_number_vector.pop_back();
    }

   
}