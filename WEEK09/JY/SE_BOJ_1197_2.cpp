// 1197 최소 스패닝 트리

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define cost first
#define vertex second

using namespace std;

vector<pair<int, int> > graph[100001];
int vis[100001];

// 프림
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int v, e, a, b, c;
    cin >> v >> e;

    for (int i=0; i<e; i++) {
        cin >> a >> b >> c;
        // 무방향 그래프
        graph[a].push_back(make_pair(c, b));
        graph[b].push_back(make_pair(c, a));
    }

    priority_queue<vector<int>, vector<vector<int> >, greater<vector<int> > > pq;

    vector<int> node;
    for (pair<int, int> temp : graph[1]) {
        node.push_back(temp.cost); // 0 - 비용
        node.push_back(1); // 1- 기준 노드
        node.push_back(temp.vertex); // 2 - 살펴볼노드
        pq.push(node);
        node.clear();
    }
    vis[1] = 1;

    int cnt = 0;
    int ans = 0;
    while (!pq.empty()) {
        vector<int> cur = pq.top();
        pq.pop();

        int nxt = cur[2];

        // 이미 연결됨
        if (vis[nxt] == 1) continue;

        for (pair<int, int> temp : graph[nxt]) {
            node.push_back(temp.cost); // 0 - 비용
            node.push_back(1); // 1- 기준 노드
            node.push_back(temp.vertex); // 2 - 살펴볼노드
            pq.push(node);
            node.clear();
        }
        vis[nxt] = 1;
        cnt++;
        ans += cur[0];

        if (cnt == v-1) break;
    }

    cout << ans << "\n";

    return 0;
}