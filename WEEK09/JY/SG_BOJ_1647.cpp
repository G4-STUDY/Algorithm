// 1647 도시 분할 계획

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int p[100001];

int find(int x) {
    if (p[x] < 0) return x;
    return p[x] = find(p[x]);
}

bool uni(int x, int y) {
    x = find(x);
    y = find(y);

    if (x==y) return false;
    p[y] = x;
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, a, b, c;
    cin >> n >> m;

    fill(p, p+n+1, -1);

    vector<int> node;
    priority_queue<vector<int>, vector<vector<int> >, greater<vector<int> > > pq;

    for (int i=0; i<m; i++) {
        cin >> a >> b >> c;
        node.push_back(c);
        node.push_back(a);
        node.push_back(b);
        pq.push(node);
        node.clear();
    }

    int ans = 0;
    int cnt = 0;
    int maxVal = -1; // 가장 큰 가중치 저장

    // 크루스칼
    // 최소 스패닝 트리를 만들고 가장 큰 가중치 지운다
    while (!pq.empty()) {
        vector<int> cur = pq.top();
        pq.pop();

        c = cur[0];
        a = cur[1];
        b = cur[2];

        if (uni(a, b)) {
            ans += c;
            maxVal = max(maxVal, c);
            cnt++;
        }

        if (cnt == n-1) break;
    }

    cout << ans - maxVal << "\n";

    return 0;
}
