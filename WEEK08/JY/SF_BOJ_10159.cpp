// 10159 저울

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define INF 10

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, a, b;
    cin >> n >> m;

    int graph[n+1][n+1];
    for (int i=0; i<n+1; i++) {
        fill(graph[i], graph[i]+n+1, INF);
        graph[i][i] = 0;
    }

    for (int i=0; i<m; i++) {
        cin >> a >> b;
        graph[a][b] = 1;
        graph[b][a] = -1;
    }

    for (int k=1; k<=n; k++) {
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) {
                if (graph[i][k] * graph[k][j] == 1) {
                    cout << i << " " << j << "\n";
                    graph[i][j] = graph[i][k];
                    graph[j][i] = -graph[i][k];
                }
            }
        }
    }

    int cnt = 0;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            if (graph[i][j] == INF) {
                cnt++;
            }
        }
        cout << cnt << "\n";
        cnt = 0;
    }


    return 0;
}