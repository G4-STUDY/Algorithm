// 11657 타임머신

/**
 * 1. 시작 노드를 정한다.
 * 2. 정점수-1번 반복하며 모든 간선을 확인한다
    (다익스트라처럼 내 간선만 보는 것 아님!, 모든 간선)
 * 3. 음의 사이클을 확인하고 싶다면 정점수만큼 반복한다.
 *   이때 갱신이 일어난다면 음의 사이클이 있는 것
 */

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define INF 0x3f3f3f3f

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m,a,b,c;
    cin >> n >> m;

    vector<int> graph[m];
    for (int i=0; i<m; i++) {
        cin >> a >> b >> c;
        graph[i].push_back(a);
        graph[i].push_back(b);
        graph[i].push_back(c);
    }

    long long dist[n+1];
    fill(dist, dist+n+1, INF);
    dist[1] = 0;

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            int from = graph[j][0];
            int to = graph[j][1];
            int cost = graph[j][2];

            if (dist[from] == INF) continue;
            if (dist[to] > dist[from] + cost) {
                dist[to] = dist[from] + cost;

                if (i == n-1) {
                    cout << -1;
                    return 0;
                }
            }
        }
    }

    for (int i=2; i<=n; i++) {
        if (dist[i] == INF) dist[i] = -1;
        cout << dist[i] << "\n";
    }

    return 0;
}