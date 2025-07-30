#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector <int> v[10003];
queue <int> q;
int N, M;
int a, b;
int max_cnt;

priority_queue <pair<int, int>> pq;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;
    for (int u = 0; u < M; u++) {
        cin >> a >> b;
        v[b].push_back(a);
    }
    
    for (int u = 1; u <= N; u++) {
        int vis[10003] = { 0 };
        int cnt = 0;
        vis[u] = 1;
        q.push(u);
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (auto nxt : v[cur]) {
                if (vis[nxt] == 1) continue;
                vis[nxt] = 1;
                q.push(nxt);
                cnt++;
            }
        }
        pq.push({ cnt, -u });
    }

    int max_computer_num = pq.top().first;
    for (int u = 1; u <= N; u++) {
        cout << -pq.top().second << ' ';
        pq.pop();
        if (pq.empty() || pq.top().first != max_computer_num) return 0;
        max_computer_num = pq.top().first;
    }
    return 0;
}
