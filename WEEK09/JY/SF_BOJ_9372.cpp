// 9372 상근이의 여행

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int p[1001];

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

    int t, n, m, a, b;
    cin >> t;

    while (t--) {
        cin >> n >> m;

        fill(p, p+n+1,-1);

        pair<int, int> node;
        priority_queue< pair<int, int>,
                        vector<pair<int,int> >,
                        greater<pair<int, int> > > pq;

        for (int i = 0; i<m; i++) {
            cin >> a >> b;
            node.first = a;
            node.second = b;
            pq.push(node);
        }

        // 크루스칼
        int ans = 0;
        while(!pq.empty()) {
            pair<int, int> cur = pq.top();
            pq.pop();

            a = cur.first;
            b = cur.second;

            if (uni(a,b)) {
                ans++;
            }

            if (ans == n-1) break;
        }
        cout << ans << "\n";
    }


    return 0;
}
