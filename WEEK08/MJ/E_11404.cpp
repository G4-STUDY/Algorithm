#include <iostream>
using namespace std;

int N, M;
int a, b, c;
int temp;
int cost[102][102];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;
    for (int u = 0; u < M; u++) {
        cin >> a >> b >> c;
        if (cost[a][b] == 0 || cost[a][b] > c) cost[a][b] = c;
    }

    for (int u = 1; u <= N; u++) {
        for (int v = 1; v <= N; v++) {
            for (int w = 1; w <= N; w++) {
                if (v == w || !cost[v][u] || !cost[u][w]) continue;
                temp = cost[v][u] + cost[u][w];
                if (cost[v][w] == 0 || cost[v][w] > temp) cost[v][w] = temp;
            }
        }
    }

    for (int u = 1; u <= N; u++) {
        for (int v = 1; v <= N; v++) {
            cout << cost[u][v] << ' ';
        }
        cout << '\n';
    }

    return 0;
}
