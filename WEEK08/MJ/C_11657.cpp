#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define X first
#define Y second
vector <pair<pair<int, int>, int>> adj;
long long dist[503];
int N, M, A, B, C;
int INF = 5000005;

void PRINT() {
    for (int i = 2; i <= N; i++) {
        if (dist[i] == INF) cout << -1 << '\n';
        else cout << dist[i] << '\n';
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;
    adj.push_back({ { 0, 0 }, 0 });
    for (int u = 0; u < M; u++) {
        cin >> A >> B >> C;
        adj.push_back({ { A, B }, C });
    }
    fill(dist, dist + N + 1, INF);
    dist[1] = 0;
    for (int u = 2; u <= N; u++) {
        for (int v = 1; v <= M; v++) {
            int cur_idx = adj[v].X.X;
            int nxt_idx = adj[v].X.Y;
            int nxt_dist = adj[v].Y;
            if (dist[cur_idx] == INF) continue;
            if (dist[nxt_idx] > dist[cur_idx] + nxt_dist) {
                dist[nxt_idx] = dist[cur_idx] + nxt_dist;
            }
        }
    }
    for (int v = 1; v <= M; v++) {
        int cur_idx = adj[v].X.X;
        int nxt_idx = adj[v].X.Y;
        int nxt_dist = adj[v].Y;
        if (dist[cur_idx] == INF) continue;
        if (dist[nxt_idx] > dist[cur_idx] + nxt_dist) {
            cout << -1;
            return 0;
        }
    }
    PRINT();
    return 0;
}
