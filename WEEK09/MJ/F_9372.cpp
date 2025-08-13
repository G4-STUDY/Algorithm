#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int T, N, M, a, b;
int cnt;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    for (int u = 0; u < T; u++) {
        cin >> N >> M;
        for (int v = 0; v < M; v++) {
            cin >> a >> b;
        }
        cout << N - 1 << '\n';
    }
    return 0;
}
