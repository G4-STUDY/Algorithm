// 1753 최단경로

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define INF 0x3f3f3f3f
#define cost first
#define vertex second

vector<pair<int, int> > graph[20001]; // 가중치, 정점
int d[20001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int v, e, k;
    cin >> v >> e >> k;

    int a, b, c;
    for (int i=0; i<e; i++) {
        cin >> a >> b >> c;
        graph[a].push_back(make_pair(c,b));
    }

    fill(d, d+v+1, INF);
    d[k] = 0;

    priority_queue<pair<int, int>, vector<pair<int,int> >, greater<pair<int, int> > >pq;
    pq.push(make_pair(0, k)); // 가중치, 정점

    while (!pq.empty()) {
        pair<int, int> cur = pq.top();
        pq.pop();

        // 의미 없는 노드는 지나감
        if (d[cur.vertex] != cur.cost) continue;

        // 현재 정점과 이어진 모든 노드를 순회하며 큐에 넣음
        for (pair<int, int> node : graph[cur.vertex]) {
            if (d[node.vertex] > d[cur.vertex] + node.cost) {
                d[node.vertex] = d[cur.vertex] + node.cost;
                pq.push(make_pair(d[node.vertex], node.vertex));
            }
        }
    }

    for (int i=1; i<=v; i++) {
        if (d[i] == INF) cout << "INF ";
        else cout << d[i] << " ";
    }

    return 0;
}
