#include <iostream>
#include <vector>
using namespace std;
vector <int> v;
int N, M, i, j, k;

int find(int x) {
    if (v[x] < 0) return x;
    return v[x] = find(v[x]);
}

bool uni(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return false;
    v[b] = a;
    return true;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;
    for (int u = 0; u <= N; u++) v.push_back(-1);
    for (int u = 0; u < M; u++) {
        cin >> i >> j >> k;
        if (i == 0)  uni(j, k);
        else {
            if (find(j) == find(k)) cout << "YES" << '\n';
            else cout << "NO" << '\n';
        }

    }
    return 0;
}
