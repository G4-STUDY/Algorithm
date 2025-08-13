// 16389 행성 연결

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define ll long long

ll graph[1001][1001];
int vis[1001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            cin >> graph[i][j];
        }
    }

    // 프림
    vector<int> node;
    priority_queue<vector<int>,
                        vector<vector<int> >,
                        greater<vector<int> > > pq;

    // 임의의 노드 1번과 연결된 정점을 모두 넣음
    for (int i=1; i<=n; i++) {
        node.push_back(graph[1][i]); // 비용
        node.push_back(1); // 본인
        node.push_back(i); // 연결된 노드
        pq.push(node);
        node.clear();
    }
    vis[1] = 1;

    ll ans = 0;
    int cnt = 0;
    while (!pq.empty()) {
        vector<int> cur = pq.top();
        pq.pop();

        int c = cur[0];
        int a = cur[1];
        int b = cur[2];

        // 이미 방문했으면 패스
        if (vis[b] == 1) continue;

        ans += c;
        cnt++;
        vis[b] = 1;

        // 정점을 모두 포함했다면 종료
        if (cnt == n-1) break;

        for (int i=1; i<=n; i++) {
            node.push_back(graph[b][i]);
            node.push_back(b);
            node.push_back(i);
            pq.push(node);
            node.clear();
        }

    }

    cout << ans << "\n";

    return 0;
}