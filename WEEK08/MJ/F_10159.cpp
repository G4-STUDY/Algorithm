#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector <int> adj1[103];
vector <int> adj2[103];
int N, M, a, b;
int result[103];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;
    for (int u = 0; u < M; u++) {
        cin >> a >> b;
        adj1[a].push_back(b); // a > b 인 경우를 adj1에 저장
        adj2[b].push_back(a); // b < a 인 경우를 adj2에 저장
    }
    for (int u = 1; u <= N; u++) { // adj1 그래프에서 각 원소를 시작점으로 BFS
        queue <int> q;
        int vis[103] = { 0 };
        q.push(u);
        vis[u] = 1;
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (auto nxt : adj1[cur]) {
                if (vis[nxt] == 1) continue;
                vis[nxt] = 1;
                result[nxt]++;
                q.push(nxt);
            }
        }
    }
    for (int u = 1; u <= N; u++) { // adj2 그래프에서 각 원소를 시작점으로 BFS
        queue <int> q;
        int vis[103] = { 0 };
        q.push(u);
        vis[u] = 1;
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (auto nxt : adj2[cur]) {
                if (vis[nxt] == 1) continue;
                vis[nxt] = 1;
                result[nxt]++;
                q.push(nxt);
            }
        }
    }
    // result 배열에 각 물건(인덱스)과 비교 결과를 알 수 있는 물건의 개수가 저장됨 
    for (int u = 1; u <= N; u++) cout << N - result[u] - 1 << '\n';
    return 0;
}
