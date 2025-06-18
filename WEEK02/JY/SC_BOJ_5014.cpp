// 5014 스타트링크

#include <iostream>
#include <queue>
using namespace std;

int vis[1000001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int f, s, g, u, d;
    cin >> f >> s >> g >> u >> d;

    // 강호가 이미 스타트링크 층에 있다면 0 출력 후 종료
    if (s == g) {
        cout << 0 << "\n";
        return 0;
    }

    fill(vis, vis+1000001, -1);

    //강호의 위치에서 bfs 시작
    queue<int> q;
    q.push(s);
    vis[s] = 0;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        int next = 0;
        for (int i=0; i<2; i++) {
            if (i == 0) next = cur + u; //위로 이동
            if (i == 1) next = cur - d; //아래로 이동

            //건물 층을 벗어나는 경우 이동X
            if (next < 1 || next > 1000000) continue;

            //이전에 방문하지 않은 경우 방문
            if (vis[next] == -1) {
                q.push(next);
                vis[next] = vis[cur] + 1;
            }
        }
    }

    // 스타트링크 층에 몇번만에 왔는지 출력
    if (vis[g] == -1) {
        cout << "use the stairs" << "\n";
    }
    else {
        cout << vis[g] << "\n";
    }

    return 0;
}