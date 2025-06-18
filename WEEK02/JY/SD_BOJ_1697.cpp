// 1697 숨바꼭질

#include <iostream>
#include <queue>
using namespace std;

int vis[200001]; //수빈이가 해당 칸에 도착한 시간을 저장

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    // 수빈이와 동생의 위치가 같은 경우 0초
    if (n == k) {
        cout << "0" < "\n";
        return 0;
    }

    queue<int> q;
    fill(vis, vis + 200001, 0);

    q.push(n);
    vis[n] = 1;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        int next; // 수빈이의 위치 이동
        for (int i=0; i<3; i++) {
            if (i == 0) next = cur - 1;
            else if (i == 1) next = cur + 1;
            else if (i == 2) next = cur * 2;

            // 동생을 찾은 경우 출력 후 종료
            if (next == k) {
                cout << vis[cur] << "\n";
                return 0;
            }

            if (next < 0 || next > 200001) continue;

            // 이동한 칸까지 오는데 걸린 시간 저장
            if (vis[next] == 0) {
                q.push(next);
                vis[next] = vis[cur] + 1;
            }
        }
    }

    return 0;
}