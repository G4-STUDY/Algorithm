#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector <pair<int, int>> adj[803];
priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int dist[803];
int INF = 800008;
int N, E;
int a, b, c;
int v1, v2;

int result1, result2;

void DAIK(int start_idx) {
    fill(dist, dist + N + 1, INF);
    pq.push({ 0, start_idx });
    dist[start_idx] = 0;
    while (!pq.empty()) {
        int cur_dist = pq.top().first;
        int cur_idx = pq.top().second;
        pq.pop();
        if (dist[cur_idx] != cur_dist) continue;
        for (auto nxt : adj[cur_idx]) {
            if (dist[nxt.first] <= (cur_dist + nxt.second)) continue;
            dist[nxt.first] = cur_dist + nxt.second;
            pq.push({ dist[nxt.first], nxt.first});
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> E;
    for (int u = 0; u < E; u++) {
        cin >> a >> b >> c;
        adj[a].push_back({ b, c });
        adj[b].push_back({ a, c });
    }
    cin >> v1 >> v2;

    DAIK(1);
    if (dist[v1] == INF) {
        cout << -1;
        return 0;
    }
    else result1 += dist[v1];

    DAIK(v1);
    if (dist[v2] == INF) {
        cout << -1;
        return 0;
    }
    else result1 += dist[v2];

    DAIK(v2);
    if (dist[N] == INF) {
        cout << -1;
        return 0;
    }
    else result1 += dist[N];
    //----------------------------------------
    DAIK(1);
    if (dist[v2] == INF) {
        cout << -1;
        return 0;
    }
    else result2 += dist[v2];

    DAIK(v2);
    if (dist[v1] == INF) {
        cout << -1;
        return 0;
    }
    else result2 += dist[v1];

    DAIK(v1);
    if (dist[N] == INF) {
        cout << -1;
        return 0;
    }
    else result2 += dist[N];
    cout << min(result1, result2);
    return 0;
}
