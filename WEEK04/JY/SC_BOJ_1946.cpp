// 1946 신입 사원

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tc, n;
    cin >> tc;

    vector<pair<int, int> > v;

    for (int i=0; i<tc; i++) {
        cin >> n;
        int a, b;
        for (int i=0; i<n; i++) {
            cin >> a >> b;
            v.push_back(make_pair(a,b));
        }

        sort(v.begin(), v.end());

        int idx = v[0].second;
        int cnt = 1;
        for (int i=1; i<n; i++) {
            if (idx > v[i].second) {
                idx = v[i].second;
                cnt ++;
            }
        }
        cout << cnt << "\n";
        v.clear();
    }


    return 0;
}