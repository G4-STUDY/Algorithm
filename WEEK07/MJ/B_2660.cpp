#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

vector <int> v[52];
queue <int> q;
int N;
int a, b;

priority_queue <pair<int, int>> pq;
stack <int> s;
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    while (true) {
        cin >> a >> b;
        if (a == -1 && b == -1) break;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    
    int min_point = 50;
    for (int u = 1; u <= N; u++) {
        int vis[52] = {0};
        int point = 0;
        vis[u] = 1;
        q.push(u);
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (auto nxt : v[cur]) {
                if (vis[nxt] != 0) continue;
                vis[nxt] = vis[cur] + 1;
                if (vis[nxt] > point) point = vis[nxt];
                q.push(nxt);
            }
        }
        if (point < min_point) min_point = point;
        pq.push({ -point, u });
    }

    int cnt = 0;
    while (!pq.empty()) {
        s.push(pq.top().second);
        pq.pop();
        cnt++;
        if (pq.top().first != (-min_point)) break;
    }
    cout << min_point - 1 << ' ' << cnt << '\n';
    while (!s.empty()) {
        cout << s.top() << ' ';
        s.pop();
    }
    return 0;
}
