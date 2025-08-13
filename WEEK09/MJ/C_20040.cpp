#include <iostream>
#include <vector>
using namespace std;
vector <int> v;
int N, M, a, b;

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
    for (int u = 0; u < N; u++) v.push_back(-1);
    for (int u = 1; u <= M; u++) {
        cin >> a >> b;
        if (Find(a) == Find(b)) { // Find(a) == Find(b) 일때 사이클이 처음 생김
                                  // a와 b는 이미 같은 그룹이므로 이 둘을 이으면 사이클
            cout << u;
            return 0;
        }
        Union(a, b);
    }
    cout << 0;
    return 0;
}
