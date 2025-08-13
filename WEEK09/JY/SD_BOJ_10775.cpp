// 10775 공항

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int parent[100001];

int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int g, p, gate;
    cin >> g >> p;

    // 본인이 사용할 수 있는 gate의 최대값을 저장
    for (int i=1; i<=g; i++) {
        parent[i] = i;
    }

    int ans = 0;
    // 사용할 수 있는 게이트가 없으면 true
    bool end = false;
    while (p--) {
        cin >> gate;

        if (end) continue;

        // 내가 사용할 수 있는 게이트의 최대값을 가져옴
        // 0이면 다 쓴 것
        int nxt = find(gate);
        if (nxt == 0) {
            end = true;
            continue;
        }
        // nxt 게이트를 사용했으니, 이제 nxt-1 게이트가 다음 후보가 되도록 부모 갱신
        parent[nxt] = find(nxt - 1);
        ans++;
    }

    cout << ans << "\n";

    return 0;
}