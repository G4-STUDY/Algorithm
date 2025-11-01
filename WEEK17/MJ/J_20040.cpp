// 배열에 -1 안넣고 풀어서 계속 틀렸음

#include <iostream>
#include <vector>

using namespace std;

vector <int> arr;

int Find(int x) {
    if (arr[x] < 0) return x;
    return arr[x] = Find(arr[x]);
}

bool Union(int x, int y) {
    x = Find(x);
    y = Find(y);
    if (x == y) return true;
    arr[x] = y;
    return false;
}

int n, m;
int a, b;

int main() {
    cin >> n >> m;
    for (int u = 0; u < n; u++) arr.push_back(-1);
    for (int u = 1; u <= m; u++) {
        cin >> a >> b;
        if (Union(a, b)) {
            cout << u;
            return 0;
        }
    }
    cout << 0;
    return 0;
}
