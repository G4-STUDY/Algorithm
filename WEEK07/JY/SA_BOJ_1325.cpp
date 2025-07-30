// 1325 효율적인 해킹

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int> > graph(10001);
int cnt = 0;

void dfs(int idx, int vis[]) {
    for (int node: graph[idx]) {
        if (vis[node] == 1) continue;

        vis[node] = 1;
        cnt++;
        dfs(node, vis);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, a, b;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        graph[b].push_back(a);
    }

    int vis[n+1];
    int result[n+1];
    int maxVal = -1;
    for (int i = 1; i <= n; i++) {
        fill(vis, vis + n + 1, 0);
        vis[i] = 1;
        dfs(i, vis);
        maxVal = max(maxVal, cnt);
        result[i] = cnt;
        cnt = 0;
    }

    for (int i = 1; i <= n; i++) {
        if (result[i] == maxVal) {
            cout << i << " ";
        }
    }

    return 0;
}
