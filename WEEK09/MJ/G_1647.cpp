#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define X first
#define Y second

vector <int> v;
priority_queue<pair <int, pair<int, int>>> pq;
int N, M, a, b, c;
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
    cin >> N >> M;
    for (int u = 0; u <= N; u++) v.push_back(-1);
    for (int u = 0; u < M; u++) {
        cin >> a >> b >> c;
        pq.push({ -c,{a,b} });
    }
    for (int u = 0; u < M; u++) {
        int curr_cost = -pq.top().X;
        int curr_node_1 = pq.top().Y.X;
        int curr_node_2 = pq.top().Y.Y;
        pq.pop();
        if (Find(curr_node_1) == Find(curr_node_2)) continue;
        Union(curr_node_1, curr_node_2);
        cnt++;
        if (cnt == N - 1) { // 이때 하나의 최소신장트리가 완성됨.
                            // 그때 트리에 추가하는 노드를 추가하지 않으므로서 
                            // 마을을 두개로 나눔.
            cout << cost;
            return 0;
        }
        cost += curr_cost;
    }

    return 0;
}
