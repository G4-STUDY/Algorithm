// 1865 웜홀

#include <iostream>
#include <algorithm>
#include <vector>

#define INF 0x3f3f3f3f

using namespace std;

int tc, n, m, w, s, e, t;
vector<tuple<int, int, int> > graph;
int dist[501];

// 음수 사이클 o -> true, x -> false
bool bellmanFord(int idx) {
    fill(dist, dist+n+1, INF);
    dist[idx] = 0;

    for (int i=0; i<n; i++) {
        for (tuple<int, int, int> node : graph) {
            int from = get<0>(node);
            int to = get<1>(node);
            int cost = get<2>(node);

            if (dist[from] == INF) continue;
            if (dist[to] > dist[from] + cost) {
                dist[to] = dist[from] + cost;

                if (i == n-1) return true;
            }
        }
    }

    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> tc;

    while (tc--) {
        cin >> n >> m >> w;
        // 초기화
        graph.clear();

        for (int i=0; i<=n; i++) {
            graph.push_back(make_tuple(0, i, 0));
        }

        // 입력
        for (int i=0; i<m; i++) {
            cin >> s >> e >> t;
            // 도로는 양방향
            graph.push_back(make_tuple(s, e, t));
            graph.push_back(make_tuple(e, s, t));
        }
        for (int i=0; i<w; i++) {
            cin >> s >> e >> t;
            graph.push_back(make_tuple(s, e, -t));
        }

        // 벨만포드 - 모든 정점에 대해 음수 사이클 확인
        bool ans = bellmanFord(0);

        if (ans) cout << "YES\n";
        else cout << "NO\n";

    }

    return 0;
}