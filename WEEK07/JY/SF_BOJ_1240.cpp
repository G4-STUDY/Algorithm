// 1240 노드사이의 거리

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<vector<pair<int, int> > > graph(1001);
int vis[1001];
int ans = 0;
int found = 0;

void dfs(int idx, int end) {
    if (idx == end) {
        found = 1;
        return;
    }

    for (pair<int,int> node : graph[idx]) {
        if (vis[node.first] == 1) continue;

        vis[node.first] = 1;
        ans += node.second;
        dfs(node.first, end);
        if (found == 1) return;
        ans -= node.second;
    }

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, a, b, cost;
    cin >> n >> m;
    for (int i=0; i<n-1; i++) {
        cin >> a >> b >> cost;

        graph[a].push_back(make_pair(b, cost));
        graph[b].push_back(make_pair(a, cost));
    }

    for (int i=0; i<m; i++) {
        cin >> a >> b;
        fill(vis, vis+n+1, 0);
        ans = 0;
        found = 0;

        vis[a] = 1;
        dfs(a, b);
        cout << ans << "\n";
    }

    return 0;
}