#include <iostream>
#include <queue>
#include <vector>

#define Cost first
#define Node second

using namespace std;

priority_queue <pair <int, int>> pq;

vector <pair <int, int>> adj[10003];
int vis[10003];

int N, M;
int a, b, c;
int st, en;
int result = 2000000000;

int main() {
    ios::sync_with_stdio(false);
	cin.tie(0);
    cin >> N >> M;
    for (int u = 0; u < M; u++) {
        cin >> a >> b >> c;
        adj[a].push_back({c, b});
        adj[b].push_back({c, a});
    }
    
    cin >> st >> en;
    pq.push({2000000000, st});
    vis[st] = 2000000000;
    while (!pq.empty()) {
        int cur_node = pq.top().Node;
        int cur_cost = pq.top().Cost;
        pq.pop();
        if (vis[cur_node] != 1 && cur_cost < result) result = cur_cost;
        vis[cur_node] = 1;
        //cout << cur_node << ' ' << cur_cost << '\n';
        if (cur_node == en) {
            cout << result;
            return 0;
        }
        for (auto nxt : adj[cur_node]) {
            if (vis[nxt.Node] == 1) continue;
            pq.push({nxt.Cost, nxt.Node});
        }
    }
    
    return 0;
}
