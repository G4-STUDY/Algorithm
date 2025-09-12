#include <string>
#include <vector>
#include <queue>

using namespace std;

priority_queue <vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

int p[103];


int Find(int x) {
    if (p[x] < 0) return x;
    return p[x] = Find(p[x]);
}

bool Union(int x, int y) {
    x = Find(x);
    y = Find(y);
    if (x == y) return false;
    p[y] = x;
    return true;
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    fill(p, p + n, -1);
    for (int u = 0; u < costs.size(); u++) pq.push({costs[u][2], costs[u][0], costs[u][1]});
    
    while (!pq.empty()) {
        int a = pq.top()[1];
        int b = pq.top()[2];
        int cost = pq.top()[0];
        pq.pop();
        if (!Union(a, b)) continue;
        answer += cost;
    }
    return answer;
}
