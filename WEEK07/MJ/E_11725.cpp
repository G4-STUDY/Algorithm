#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;
int a, b;
vector <int> adj[100002];
int vis[100002];
queue <int> q;
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    for (int u = 0; u < N - 1; u++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    q.push(1);
    vis[1] = 1;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (auto nxt : adj[cur]) {
            if (vis[nxt] != 0) continue;
            vis[nxt] = vis[cur] + 1;
            q.push(nxt);
        }
    }
  
    for (int u = 2; u <= N; u++) {
        for (int v = 0; v < adj[u].size(); v++) {
            if (vis[adj[u][v]] == vis[u] - 1) {
                cout << adj[u][v] << '\n';
                break;
            }
        }
    }
    return 0;
}
