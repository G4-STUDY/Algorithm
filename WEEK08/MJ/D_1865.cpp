#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define X first
#define Y second
int TC, N, M, W, S, E, T;
int INF = 5000005;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> TC;
    for (int k = 0; k < TC; k++) {
        cin >> N >> M >> W;
        vector <pair<pair<int, int>, int>> adj;
        long long dist[503] = { 0 };
        bool flag = false;
        adj.push_back({ { 0, 0 }, 0 });
        for (int u = 0; u < M; u++) {
            cin >> S >> E >> T;
            adj.push_back({ { S, E }, T }); // 도로는 방향이 없으므로
            adj.push_back({ { E, S }, T }); // S->E 방향과 E->S 방향 모두 adj에 저장
        }
        for (int u = 0; u < W; u++) {
            cin >> S >> E >> T;
            adj.push_back({ { S, E }, -T }); // 웜홀은 시간이 거꾸로 가므로 -T값을 adj에 저장
        }
        fill(dist, dist + N + 1, INF);
        dist[1] = 0;
        for (int u = 2; u <= N; u++) {
            for (int v = 1; v <= 2 * M + W; v++) {
                int cur_idx = adj[v].X.X;
                int nxt_idx = adj[v].X.Y;
                int nxt_dist = adj[v].Y;
                if (dist[nxt_idx] > dist[cur_idx] + nxt_dist) {
                    dist[nxt_idx] = dist[cur_idx] + nxt_dist;
                }
            }
        }
        for (int v = 1; v <= 2 * M + W; v++) {
            int cur_idx = adj[v].X.X;
            int nxt_idx = adj[v].X.Y;
            int nxt_dist = adj[v].Y;
            if (dist[nxt_idx] > dist[cur_idx] + nxt_dist) {
                flag = true;  // 음의 순환이 있으면 flag를 true로 갱신
                break;
            }
        }
        if (flag) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
    return 0;
}
