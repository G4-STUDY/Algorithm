#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int V, E, K;
int a, b, c;
vector <pair<int, int>> adj[20002];
priority_queue <pair<int, int>> pq;
int dist[20002];

void PRINT() {
    for (int u = 1; u <= V; u++) {
        if (dist[u] == 200002) cout << "INF" << '\n';
        else cout << dist[u] << '\n';
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> V >> E >> K;
    for (int u = 0; u < E; u++) {
        cin >> a >> b >> c;
        adj[a].push_back({ b,c });
    }
    fill(dist, dist + V + 1, 200002);
    dist[K] = 0;
    pq.push({ 0, K });
    while (!pq.empty()) {
        int cur_dist = -pq.top().first;
        int cur_node = pq.top().second;
        pq.pop();
        if (dist[cur_node] != cur_dist) continue;
        for (auto nxt : adj[cur_node]) {
            int new_dist = nxt.second + cur_dist;
            if (new_dist < dist[nxt.first]) {
                dist[nxt.first] = new_dist;
                pq.push({ -new_dist, nxt.first });
            }
        }
    }
    PRINT();
    return 0;
}
