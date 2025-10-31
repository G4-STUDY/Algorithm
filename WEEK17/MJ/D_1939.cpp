#include <iostream>
#include <queue>
#include <vector>

#define Cost first
#define Node second

using namespace std;

priority_queue <pair <int, int>> pq;

vector <pair <int, int>> adj[10003];
long long vis[10003];

int N, M;
int a, b, c;
int st, en;
int result = 2000000000;

int main() {
    cin >> N >> M;
    for (int u = 0; u < M; u++) {
        cin >> a >> b >> c;
        adj[a].push_back({c, b});
        adj[b].push_back({c, a});
    }
    
    cin >> st >> en;
    pq.push({2000000000, st});
    vis[st] = 1;
    while (!pq.empty()) {
        int cur_node = pq.top().Node;
        int cur_cost = pq.top().Cost;
        pq.pop();
        if (cur_cost < result) result = cur_cost;
        if (cur_node == en) {
            cout << result;
            return 0;
        }
        for (auto nxt : adj[cur_node]) {
            if (vis[nxt.Node] >= vis[cur_node] + nxt.Cost) continue;
            vis[nxt.Node] = vis[cur_node] + nxt.Cost;
            pq.push({nxt.Cost, nxt.Node});
        }
    }
    
    return 0;
}
