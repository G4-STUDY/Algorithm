// 11725 트리의 부모 찾기

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int> > v(100001);
int vis[100001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, a, b;
    cin >> n;

    for (int i=0; i<n-1; i++) {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    queue<int> q;
    q.push(1);
    vis[1] = 1;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int node : v[cur]) {
            if (vis[node] != 0) continue;

            vis[node] = cur;
            q.push(node);
        }
    }

    for (int i=2; i<=n; i++) {
        cout << vis[i] << "\n";
    }

    return 0;
}//
// Created by DSO8 on 25. 7. 30.
//
