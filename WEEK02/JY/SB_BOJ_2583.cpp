// 2583 영역 구하기

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int paper[101][101];
int vis[101][101];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int m, n, k;
    cin >> m >> n >> k;

    // 모눈종이 -> 1로 초기화
    // 방문 배열 -> 0으로 초기화
    for (int i=0; i<m; i++) {
        fill(paper[i], paper[i]+101, 1);
        fill(vis[i], vis[i]+101, 0);
    }

    // 직사각형이 그려진 부분 0으로 초기화
    // = 방문 할 수 없는 부분
    int x1, y1, x2, y2;
    for (int a=0; a<k; a++) {
        cin >> x1 >> y1 >> x2 >> y2;
        // 이차원 배열은 행(세로), 열(가로) 순이지만
        // 좌표는 x(가로), y(세로) 순이기 때문에 paper[y][x]로 사용해야 올바르게 들어감
        for (int b=y1; b<y2; b++) {
            for (int c=x1; c<x2; c++) {
                paper[b][c] = 0;
            }
        }
    }

    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, -1, 0, 1};
    queue<pair<int, int> > q;

    int cnt = 0; // 빈 부분의 개수
    int area = 0; // 빈 부분의 넓이
    vector<int> areaList;

    for (int a = 0; a<m; a++) {
        for (int b=0; b<n; b++) {
            // 종이의 빈 공간이고 이전에 방문하지 않은 경우 BFS
            if (paper[a][b] == 1 && vis[a][b] == 0) {
                q.push(make_pair(a,b));
                vis[a][b] = 1;
                area = 1;

                while (!q.empty()) {
                    pair<int, int> cur = q.front();
                    q.pop();

                    for (int c=0; c<4; c++) {
                        int x = cur.first + dx[c];
                        int y = cur.second + dy[c];

                        if (x < 0 || x >= m || y < 0 || y >=n) continue;

                        if (paper[x][y] == 1 && vis[x][y] == 0) {
                            q.push(make_pair(x,y));
                            vis[x][y] = vis[cur.first][cur.second] + 1;
                            area += 1;
                        }
                    }
                }
                cnt += 1;
                areaList.push_back(area);
            }
        }
    }

    cout << cnt << "\n";
    sort(areaList.begin(), areaList.end());
    for (int i=0; i<areaList.size(); i++) {
        cout << areaList[i] << " ";
    }

    return 0;
}