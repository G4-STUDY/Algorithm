#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define X first
#define Y second

vector <int> v;
priority_queue <pair<long long, pair<int, int>>> pq;

int N, c;
int cnt;
long long cost;
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
    cin.tie();
    cin >> N;
    for (int u = 0; u <= N; u++) v.push_back(-1);
    for (int u = 1; u <= N; u++) {
        for (int v = 1; v <= N; v++) {
            cin >> c;
            if (v > u) pq.push({ -c,{u,v} });
        }
    }
    for (int u = 0; u < N * (N - 1) / 2; u++) {
        long long curr_cost = -pq.top().X;
        int curr_node_1 = pq.top().Y.X;
        int curr_node_2 = pq.top().Y.Y;
        pq.pop();
        if (Find(curr_node_1) == Find(curr_node_2)) continue;
        Union(curr_node_1, curr_node_2);
        cnt++;
        cost += curr_cost;
        if (cnt == N - 1) {
            cout << cost;
            return 0;
        }
    }
    cout << cost;
    return 0;
}
