// 2660 회장뽑기

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n;
vector<vector<int> > graph (51);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    int a, b;
    cin >> a >> b;
    while (a != -1 && b != -1) {
        graph[a].push_back(b);
        graph[b].push_back(a);
        cin >> a >> b;
    }

    // for (int i=0; i<=n; i++) {
    //     for (int node: graph[i]) {
    //         cout << node << " ";
    //     }
    //     cout << "\n";
    // }
    // cout <<"------\n";

    int minVal = 100;

    int vis[n+1];
    int result[n+1];
    queue<int> q;

    for (int i=1; i<=n; i++) {
        fill(vis, vis+n+1, 0);

        q.push(i);
        vis[i] = 1;
        int cnt = 0;

        while (!q.empty()) {
            int cur = q.front(); q.pop();

            for (int node: graph[cur]) {
                if (vis[node] != 0) continue;

                //cout<< "vis" << cur << " " << node <<"\n";
                q.push(node);
                vis[node] = vis[cur]+1;
                cnt = vis[node];
            }
        }

        result[i] = cnt;
        minVal = min(minVal, cnt);
    }

    vector<int> ans;
    for (int i=1; i<=n; i++) {
        if (result[i] == minVal) {
            ans.push_back(i);
        }
    }

    cout << minVal-1 << " " << ans.size() << "\n";
    for (int temp: ans) {
        cout << temp << " ";
    }


    return 0;
}