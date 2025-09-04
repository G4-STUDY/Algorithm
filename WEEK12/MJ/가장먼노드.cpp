#include <string>
#include <vector>
#include <queue>

using namespace std;

vector <int> adj[20002];
int vis[20002];
queue <int> q;
int max_dist;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    for (int u = 0; u < edge.size(); u++) {
        adj[edge[u][0]].push_back(edge[u][1]);
        adj[edge[u][1]].push_back(edge[u][0]);
    }
    q.push(1);
    vis[1] = 1;
    while(!q.empty()) {
        int curr = q.front();
        q.pop();
        for (auto nxt : adj[curr]) {
            if (vis[nxt] == 0) {
                vis[nxt] = vis[curr] + 1;
                if (vis[nxt] > max_dist) {
                    max_dist = vis[nxt];
                    answer = 1;
                }
                else if (vis[nxt] == max_dist) answer++;
                q.push(nxt);
            }
        }
    }
    return answer;
}
