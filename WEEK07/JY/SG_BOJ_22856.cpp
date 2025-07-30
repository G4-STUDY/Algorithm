// 22856 트리 순회

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int l[100001];
int r[100001];
int endVal = 0;
int found = 0;
int ans = 0;

void inOrder(int idx) {
    if (l[idx] != -1) {
        inOrder(l[idx]);
    }
    endVal = idx;
    if (r[idx] != -1) {
        inOrder(r[idx]);
    }
}

void cntOrder(int idx) {

    if (l[idx] != -1) {
        ans++;
        cntOrder(l[idx]);
        if (found == 1) return;
        ans++;
    }

    if (idx == endVal) found = 1;

    if (r[idx] != -1) {
        ans++;
        cntOrder(r[idx]);
        if (found == 1) return;
        ans++;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int a, b, c;
    for (int i=0; i<n; i++) {
        cin >> a >> b >> c;
        l[a] = b;
        r[a] = c;
    }

    inOrder(1);
    cntOrder(1);

    //cout << endVal << "\n";

    cout << ans << "\n";

    return 0;
}