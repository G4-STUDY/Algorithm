#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector <int> adj1[103];
vector <int> adj2[103];

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    for (int u = 0; u < results.size(); u++) {
        adj1[results[u][0]].push_back(results[u][1]);
        adj2[results[u][1]].push_back(results[u][0]);
    }
    for (int u = 1; u <= n; u++) {
        int cnt = 1;
        int vis[103] = { 0 };
        queue <int> q;
        vis[u] = 1;
        q.push(u);
        while(!q.empty()) {
            int curr = q.front();
            q.pop();
            for (auto nxt : adj1[curr]) {
                if (vis[nxt]) continue;
                vis[nxt] = 1;
                q.push(nxt);
                cnt++;
            }
        }
        q.push(u);
        while(!q.empty()) {
            int curr = q.front();
            q.pop();
            for (auto nxt : adj2[curr]) {
                if (vis[nxt]) continue;
                vis[nxt] = 1;
                q.push(nxt);
                cnt++;
            }
        }
        if (cnt == n) answer++;
    }
    return answer;
}
