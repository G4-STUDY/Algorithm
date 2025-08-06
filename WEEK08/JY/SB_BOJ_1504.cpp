// 1504 특정한 최단 경로

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define INF 0x3f3f3f3f
#define cost first
#define vertex second

using namespace std;

int n, e, a, b, c, v1, v2;
vector<pair<int, int> > graph[801];
int dist[801];

void dijkstra(int start) {
    fill(dist, dist+n+1, INF);
    dist[start] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    pq.push(make_pair(0, start));

    while (!pq.empty()) {
        pair<int, int> cur = pq.top();
        pq.pop();

        if (cur.cost != dist[cur.vertex]) continue;

        for (pair<int, int> node : graph[cur.vertex]) {
            if (dist[node.vertex] > dist[cur.vertex] + node.cost) {
                dist[node.vertex] = dist[cur.vertex] + node.cost;
                pq.push(make_pair(dist[node.vertex], node.vertex));
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> e;

    for (int i=0; i<e; i++) {
        cin >> a >> b >> c;
        graph[a].push_back(make_pair(c, b));
        graph[b].push_back(make_pair(c, a));

    }

    cin >> v1 >> v2;

    dijkstra(1);
    int startToV1 = dist[v1];
    int startToV2 = dist[v2];

    dijkstra(v1);
    int V1ToV2 = dist[v2];
    int V1toN = dist[n];

    dijkstra(v2);
    int V2ToV1 = dist[v1];
    int V2toN = dist[n];

    int one = startToV1 + V1ToV2 + V2toN;
    int two = startToV2 + V2ToV1 + V1toN;

    int ans = -1;
    if (startToV1 == INF || V1ToV2 == INF || V2toN == INF) {
        one = INF;
    } else {
        one = startToV1 + V1ToV2 + V2toN;
    }
    if (startToV2 == INF || V2ToV1 == INF || V1toN == INF) {
        two = INF;
    } else {
        two = startToV2 + V2ToV1 + V1toN;
    }

    ans = min(one, two);
    if (ans == INF) ans = -1;;

    cout << ans << "\n";

    return 0;
}