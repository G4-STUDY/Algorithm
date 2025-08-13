// 9372 상근이의 여행

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, n, m, a, b;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        while (m--) {
            cin >> a >> b;
        }
        // 비용이 다 1이면 최소 수는 정점-1개
        cout << n-1 << "\n";
    }


    return 0;
}