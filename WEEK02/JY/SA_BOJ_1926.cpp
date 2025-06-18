// 1926 그림

#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int paper[501][501]; // input 저장
    int vis[501][501]; // 방문여부 저장
    int cnt = 0, width = 0;

    // 입력
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> paper[i][j];
        }
    }

    queue<pair<int,int> > q;
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            // 모든 칸을 탐색하며 가능한 경우 bfs 실행
            if (paper[i][j] == 1 && vis[i][j] == 0) {
                q.push(make_pair(i, j));
                vis[i][j] = 1;
                int tempWidth = 0; // 현재 그림의 넓이를 저장하기 위한 변수

                while (!q.empty()) {
                    pair<int, int> cur = q.front();
                    q.pop();
                    tempWidth += 1;

                    for (int k=0; k<4; k++) {
                        int x = cur.first + dx[k];
                        int y = cur.second + dy[k];

                        if (x <0 || x >= n || y <0 || y >= m) continue;

                        if (paper[x][y] == 1 && vis[x][y] == 0) {
                            q.push(make_pair(x, y));
                            vis[x][y] = 1;
                        }
                    }
                }

                cnt += 1; // 그림 개수 증가
                width = max(width, tempWidth); // 가장 넓은 그림의 넓이로 갱신

            }
        }
    }

    cout << cnt << "\n" << width;

    return 0;
}