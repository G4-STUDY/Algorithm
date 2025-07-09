// 15903 카드 합체 놀이

#include <iostream>
#include <algorithm>
using namespace std;

long long card[1001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin >> n >> m;

    for (int i=0; i<n; i++) {
        cin >> card[i];
    }

    // 작은 수끼리 더해야 최소 점수 획득
    while (m--) {
        sort(card, card+n);

        long long temp = card[0] + card[1];
        card[0] = temp;
        card[1] = temp;
    }

    long long ans = 0;
    for (int i=0; i<n; i++) {
        ans += card[i];
    }

    cout << ans << "\n";

    return 0;
}