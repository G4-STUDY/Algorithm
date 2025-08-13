// 1197 최소 스패닝 트리

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int p[10001];

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

// 크루스칼
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int v, e, a, b, c;
    cin >> v >> e;

    vector<int> node;
    priority_queue<vector<int>, vector<vector<int> >, greater<vector<int> > > pq;

    for (int i=0; i<e; i++) {
        cin >> a >> b >> c;
        node.push_back(c);
        node.push_back(a);
        node.push_back(b);
        pq.push(node);
        node.clear();
    }

    fill(p, p+v+2, -1);

    int ans = 0;
    int cnt = 0;
    while (!pq.empty()) {
        vector<int> cur = pq.top();
        pq.pop();

        a = cur[1];
        b = cur[2];

        if (uni(a, b)) {
            ans += cur[0];
            cnt++;
        }

        if (cnt == v-1) break;
    }

    cout << ans << "\n";

    return 0;

}


/**
 *크루스칼
 * 1. 간선 가중치 기준 오름차순 정렬
 * 2. 작은것부터 유니온 파인드
 */