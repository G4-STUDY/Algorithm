// 22040 사이클 게임

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int p[500001];

int find(int x) {
    if (p[x] < 0) return x;
    return p[x] = find(p[x]);
}

bool uni(int x, int y) {
    x = find(x);
    y = find(y);

    if (x == y) return false;
    p[y] = x;
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, a, b;
    cin >> n >> m;

    int ans = 0;
    fill(p, p+n+1, -1);
    for (int i=1; i<=m; i++) {
        cin >> a >> b;

        if (a > b) swap(a,b);

        if (find(a) == find(b)) {
            ans = i;
            break;
        }

        uni(a, b);
    }

    cout << ans << "\n";
    return 0;
}