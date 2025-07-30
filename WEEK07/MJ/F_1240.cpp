#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define Node first
#define Dist second

int N, M;
int a, b, c;
vector <pair<int,int>> adj[1002];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;
    for (int u = 0; u < N - 1; u++) {
        cin >> a >> b >> c;
        adj[a].push_back({ b,c });
        adj[b].push_back({ a,c });
    }

    for (int u = 0; u < M; u++) {
        int vis[1002] = { 0 };
        queue <int> q;
        cin >> a >> b;
        q.push(a);
        vis[a] = 1;
        while (!q.empty()) {
            int cur = q.front();
            if (cur == b) {
                cout << vis[cur] - 1 << '\n';
                break;
            }
            q.pop();
            for (auto nxt : adj[cur]) {
                if (vis[nxt.Node] != 0) continue;
                vis[nxt.Node] = vis[cur] + nxt.Dist;
                q.push(nxt.Node);
            }
        }
    }
    return 0;
}
