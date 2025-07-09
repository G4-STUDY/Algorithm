// 2240 자두

#include <iostream>
#include <algorithm>
using namespace std;

int d[1001][32];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, w;
    cin >> t >> w;

    // -1로 초기화
    for (int i=0; i<t; i++) {
        fill(d[i], d[i]+w+1, -1);
    }
    // 예외처리 하지 않기 위해 0번 인덱스 0으로 초기화
    fill(d[0], d[0]+w+1, 0);

    int num;

    //d[t][w] : t초에 w번 움직였을때의 최대값
    for (int i=1; i<=t; i++) {
        cin >> num;
        for (int j=0; j<=w; j++) {
            if (j > i) continue;
            // 움직여서 자두를 받을 수 있음
            if ((num == 1 && j%2 == 0) || (num == 2 && j%2 == 1)) {
                // 움직인 경우, 움직이지 않은 경우 중 최대값을 골라 + 1
                if (d[i-1][j] == -1) {
                    d[i][j] = d[i-1][j-1] + 1;
                }
                else {
                    d[i][j] = max(d[i-1][j], d[i-1][j-1])+1;}
            }
            // 자두 못받음
            else {
                d[i][j] = d[i-1][j];
            }
        }
    }

    int ans = -1;
    for (int i=0; i<=w; i++) {
        ans = max(ans, d[t][i]);
    }

    cout << ans << "\n";

    return 0;
}