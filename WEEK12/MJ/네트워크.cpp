#include <string>
#include <vector>
#include <queue>

using namespace std;

vector <int> adj[202];
int vis[202];
queue <int> q;

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    for (int u = 0; u < n; u++) {
        for (int v = 0; v < n; v++) {
            if (u == v) continue;
            if (computers[u][v] == 1) {
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
        }
    }
    
    for (int u = 0; u < n; u++) {
        if (vis[u] == 1) continue;
        vis[u] = 1;
        q.push(u);
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            for (auto nxt : adj[curr]) {
                if (vis[nxt] == 1) continue;
                vis[nxt] = 1;
                q.push(nxt);
            }
        }
        answer++;
    }
    
    return answer;
}
