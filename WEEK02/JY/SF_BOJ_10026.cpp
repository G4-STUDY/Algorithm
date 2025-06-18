// 10026 적록색약

#include <iostream>
#include <queue>
using namespace std;

char picture[101][101];
int vis[101][101];

int cnt1=0, cnt2=0;

int BFS(int n, int cnt) {
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, -1, 0, 1};

    queue<pair<int, int> > q;

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (vis[i][j] == 0) {
                cnt += 1;

                q.push(make_pair(i,j));
                vis[i][j] = 1;
                char color = picture[i][j];

                while (!q.empty()) {
                    pair<int, int> cur = q.front();
                    q.pop();

                    for (int k=0; k<4; k++) {
                        int x = cur.first + dx[k];
                        int y = cur.second + dy[k];

                        if (x < 0 || x >=n || y < 0 || y >= n) continue;

                        if (picture[x][y] == color && vis[x][y] == 0) {
                            q.push(make_pair(x,y));
                            vis[x][y] = 1;
                        }
                    }
                }
            }
        }
    }

    return cnt;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    //배열 초기화
    for (int i=0; i<101; i++) {
        fill(picture[i], picture[i]+101, 'a');
        fill(vis[i], vis[i]+101, 0);
    }

    //그림 입력
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> picture[i][j];
        }
    }

    //일반인
    cnt1 = BFS(n, cnt1);

    //적녹색약
    //R을 G로 변경 후 BFS
    for (int i = 0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (picture[i][j] == 'R') picture[i][j] = 'G';
        }
    }

    //방문 배열 초기화
    for (int i=0; i<101; i++) {
        fill(vis[i], vis[i]+101, 0);
    }

    cnt2 = BFS(n, cnt2);

    cout << cnt1 << "\n";
    cout << cnt2 << "\n";

    return 0;
}