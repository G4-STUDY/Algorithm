#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define X first
#define Y second

vector <int> v;
priority_queue < pair<int, pair<int, int>> > pq;
int V, E, a, b, c;
int cnt;
int cost;

int Find(int x) {
    if (v[x] < 0) return x;
    return v[x] = Find(v[x]);
}

bool Union(int i, int j) {
    i = Find(i);
    j = Find(j);
    if (i == j) return false;
    v[j] = i;
    return true;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> V >> E;
    for (int u = 0; u <= V; u++) v.push_back(-1);
    for (int u = 0; u < E; u++) {
        cin >> a >> b >> c;
        pq.push({ -c, {a, b} });
    }

    for (int u = 0; u < E; u++) {
        int curr_cost = -pq.top().X;
        int curr_node_1 = pq.top().Y.X;
        int curr_node_2 = pq.top().Y.Y;
        pq.pop();
        if (Find(curr_node_1) == Find(curr_node_2)) continue;
        Union(curr_node_1, curr_node_2);
        cnt++;
        cost += curr_cost;
        if (cnt == V - 1) {
            cout << cost;
            return 0;
        }
    }
    return 0;
}
