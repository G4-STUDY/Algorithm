#include <iostream>
#include <vector>
using namespace std;
vector <int> v;
int T, N, K, M, i, j;

int Find(int x) {
    if (v[x] < 0) return x;
    return v[x] = Find(v[x]);
}

bool Union(int a, int b) {
    a = Find(a);
    b = Find(b);
    if (a == b) return false;
    v[b] = a;
    return true;
}

void UnionFind() {
    v.clear();
    cin >> N >> K;
    for (int u = 0; u < N; u++) v.push_back(-1);
    for (int u = 0; u < K; u++) {
        cin >> i >> j;
        Union(i, j);
    }
    cin >> M;
    for (int u = 0; u < M; u++) {
        cin >> i >> j;
        if (Find(i) == Find(j)) cout << 1 << '\n';
        else cout << 0 << '\n';
    }
    cout << '\n';
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    for (int w = 0; w < T; w++) {
        cout << "Scenario " << w + 1 << ":" << '\n';
        UnionFind();
    }
    
    return 0;
}
