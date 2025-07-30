// 1043 거짓말

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;

set<int> party[51];
int visParty[51];
int visPerson[51];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, p, input, num;
    cin >> n >> m >> p;

    queue<int> q;
    for (int i=0; i<p; i++) {
        cin >> input;
        q.push(input);
        visPerson[input] = 1;
    }

    for (int i=0; i<m; i++) {
        cin >> num;
        for (int j=0; j<num; j++) {
            cin >> input;
            party[i].insert(input);
        }
    }

    while (!q.empty()) {
        int cur = q.front(); q.pop();

        for (int i=0; i<m; i++) {
            // 없는 경우
            if (party[i].find(cur) == party[i].end()) continue;

            // 있는 경우
            for (int temp : party[i]) {
                if (visPerson[temp] == 1) continue;

                q.push(temp);
                visPerson[temp] = 1;
            }
            visParty[i] = 1;
        }
    }

    int ans = 0;
    for (int i=0; i<m; i++) {
        if (visParty[i] == 0) ans++;
    }

    cout << ans << "\n";

    return 0;
}