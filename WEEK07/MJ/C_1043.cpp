#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

int N, M;
int true_n;
int true_people[52];

int party_n;
vector <int> party_people[52];
vector <int> adj[52];

queue <int> q;
int vis[52];

int cnt;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;
    cin >> true_n;
    for (int u = 0; u < true_n; u++) cin >> true_people[u];
    for (int u = 0; u < M; u++) {
        cin >> party_n;
        int temp_1 = 0;
        int temp_2 = 0;
        for (int v = 0; v < party_n; v++) {
            cin >> temp_1;
            party_people[u].push_back(temp_1);
            adj[temp_2].push_back(temp_1);
            adj[temp_1].push_back(temp_2);
            temp_2 = temp_1;
        }
    }

    for (int u = 0; u < true_n; u++) {
        q.push(true_people[u]);
        vis[true_people[u]] = 1;
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (auto nxt : adj[cur]) {
                if (nxt == 0 || vis[nxt] == 1) continue;
                vis[nxt] = 1;
                q.push(nxt);
            }
        }
    }

    for (int u = 0; u < M; u++) {
        bool flag = false;
        for (int v = 0; v < party_people[u].size(); v++) {
            if (vis[party_people[u][v]] == 1) flag = true;
        }
        if (flag == false) cnt++;
    }
    cout << cnt;
    return 0;
}
