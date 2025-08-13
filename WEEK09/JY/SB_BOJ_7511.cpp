// 7511 소셜 네트워킹 어플리케이션

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int p[1000001];

int find(int x) {
    if (p[x] < 0) return x;
    return p[x] = find(p[x]);
}

bool uni(int x, int y){
    x = find(x);
    y = find(y);

    if (x == y) return false;
    p[x] = y;
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tc, n, k, a, b, m, u, v;
    cin >> tc;

    for (int i=1; i<=tc; i++) {
        cout << "Scenario " << i << ":\n";

        cin >> n >> k;
        fill(p, p+n+1,-1);

        while (k--) {
            cin >> a >> b;
            uni(a, b);
        }

        cin >> m;
        while (m--) {
            cin >> u >> v;
            if (find(u) == find(v)) cout << "1\n";
            else cout << "0\n";
        }
        cout << "\n";
    }


    return 0;
}