#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector <int> adj1[103];
vector <int> adj2[103];
int N, M, a, b;
int result[103];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;
    for (int u = 0; u < M; u++) {
        cin >> a >> b;
        adj1[a].push_back(b);
        adj2[b].push_back(a);
    }
    for (int u = 1; u <= N; u++) {
        queue <int> q;
        int vis[103] = { 0 };
        q.push(u);
        vis[u] = 1;
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (auto nxt : adj1[cur]) {
                if (vis[nxt] == 1) continue;
                vis[nxt] = 1;
                result[nxt]++;
                q.push(nxt);
            }
        }
    }
    for (int u = 1; u <= N; u++) {
        queue <int> q;
        int vis[103] = { 0 };
        q.push(u);
        vis[u] = 1;
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (auto nxt : adj2[cur]) {
                if (vis[nxt] == 1) continue;
                vis[nxt] = 1;
                result[nxt]++;
                q.push(nxt);
            }
        }
    }
    for (int u = 1; u <= N; u++) cout << N - result[u] - 1 << '\n';
    return 0;
}
