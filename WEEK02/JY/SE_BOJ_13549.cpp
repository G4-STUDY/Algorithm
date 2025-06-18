// 13549 숨바꼭질

#include <iostream>
#include <queue>
using namespace std;

int vis[200001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    // 수빈이와 동생이 같은 위치에 있는 경우 종료
    if (n == k) {
        cout << "0\n";
        return 0;
    }

    fill(vis, vis+200001, -1);

    // 수빈이의 위치에서 시작
    queue<int> q;
    q.push(n);
    vis[n] = 0;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        int next;
        for (int i=0; i<3; i++) {
            if (i == 0) next = cur * 2;
            else if (i == 1) next = cur - 1;
            else if (i == 2) next = cur + 1;

            if (next < 0 || next > 200000) continue;

            if (vis[next] == -1) {
                q.push(next);
                if (i == 0) {
                    // 2배 이동할 때는 0초가 걸리기 때문에 방문 시간 유지
                    vis[next] = vis[cur];
                }
                else {
                    // 이외 방문 시간 + 1
                    vis[next] = vis[cur] + 1;
                }
            }
        }
    }

    cout << vis[k] << "\n";

    return 0;
}