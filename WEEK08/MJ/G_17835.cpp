#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define Dist first
#define Idx second

vector <pair<int, int>> adj[100003];
priority_queue <pair<long long, int>> pq;
long long dist[100003];
long long result[100003];
long long INF = 1e18;
int N, M, K, a, b, c;
int temp;
int max_idx;
long long max_dist;

void PRINT() {
    for (int i = 1; i <= N; i++) {
        cout << result[i] << ' ';
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

    fill(result, result + N + 1, INF);
    for (int u = 0; u < K; u++) {
        cin >> temp;
        fill(dist, dist + N + 1, INF);
        pq.push({ 0, temp });
        dist[temp] = 0;
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
            if (result[v] > dist[v]) result[v] = dist[v];
        }
        //PRINT();
    }
    for (int v = 1; v <= N; v++) {
        if (result[v] > max_dist) {
            max_dist = result[v];
            max_idx = v;
        }
    }
    cout << max_idx << '\n' << max_dist;
    return 0;
}
