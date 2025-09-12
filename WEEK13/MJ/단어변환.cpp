#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

vector <int> adj[53];
queue <int> q;
int vis[53];

bool Connected(string a, string b) {
    int cnt = 0;
    for (int i = 0; i < a.length(); i++) {
        cnt += (a[i] != b[i]);
    }
    return (cnt == 1 ? 1 : 0);
}


int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    int target_num = 0;
    for (int u = 0; u < words.size(); u++) {
        if (words[u] == target) target_num = u + 1;
        if (Connected(words[u], begin)) {
            adj[0].push_back(u + 1);
            adj[u + 1].push_back(0);
        }
        for (int v = u + 1; v < words.size(); v++) {
            if (Connected(words[u], words[v])) {
                adj[u + 1].push_back(v + 1);
                adj[v + 1].push_back(u + 1);
            }
        }
    }
    vis[0] = 1;
    q.push(0);
    while(!q.empty()) {
        int curr = q.front();
        q.pop();
        for (auto nxt : adj[curr]) {
            if (vis[nxt]) continue;
            q.push(nxt);
            vis[nxt] = vis[curr] + 1;
            if (nxt == target_num) return vis[nxt] - 1;
        }
    }
    return 0;
}
