// 11404 플로이드

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define INF 1000000000

int graph[101][101];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, a, b, c;
    cin >> n >> m;

    for (int i=1; i<=n; i++) {
        fill(graph[i], graph[i]+n+1, INF);
    }

    for (int i=1; i<=m; i++) {
        cin >> a >> b >> c;
        graph[a][b] = min(graph[a][b], c);
    }

    for (int i=1; i<=n; i++) {
        graph[i][i] = 0;
    }

    for (int k=1; k<=n; k++) {
        for (int i=1;i<=n;i++) {
            for (int j=1;j<=n;j++) {
                if (graph[i][j] > graph[i][k] + graph[k][j]) {
                    graph[i][j] = graph[i][k] + graph[k][j];
                }
            }
        }
    }

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            if (graph[i][j] == INF) graph[i][j] = 0;
            cout << graph[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}

// 한 도시에서 출발하여 다른 도시에 도착하는 -> 단방향
// 두 도시를 연결하는 도로 -> 양방향