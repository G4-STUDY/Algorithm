#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define Dist first
#define Idx second

vector <pair<int, int>> adj[100003];
priority_queue <pair<long long, int>> pq;
long long dist[100003];
long long INF = 1e18;
int N, M, K, a, b, c;
int temp;
int max_idx;
long long max_dist;

void PRINT() {
    for (int i = 1; i <= N; i++) {
        cout << dist[i] << ' ';
    }
    cout << '\n';
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M >> K;
    for (int u = 0; u < M; u++) {
        cin >> a >> b >> c;
        adj[b].push_back({ c, a });
    }

    for (int u = 0; u < K; u++) {
        cin >> temp;
        adj[0].push_back({ 1, temp });
    }
    fill(dist, dist + N + 1, INF);
    pq.push({ 0, 0 });
    dist[0] = 0;
    while (!pq.empty()) {
        long long cur_dist = -pq.top().Dist;
        int cur_idx = pq.top().Idx;
        pq.pop();
        if (dist[cur_idx] != cur_dist) continue;
        for (auto nxt : adj[cur_idx]) {
            if (dist[nxt.Idx] <= dist[cur_idx] + nxt.Dist) continue;
            dist[nxt.Idx] = dist[cur_idx] + nxt.Dist;
            pq.push({ -dist[nxt.Idx], nxt.Idx });
        }
    }
    for (int v = 1; v <= N; v++) {
        if (dist[v] > max_dist) {
            max_dist = dist[v];
            max_idx = v;
        }
    }
    
    cout << max_idx << '\n' << max_dist - 1;
    return 0;
}
