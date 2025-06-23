// 3190 뱀

#include <iostream>
#include <queue>
using namespace std;

int board[101][101];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i=0; i<101; i++) {
        fill(board[i], board[i]+101, 0);
    }

    int n, k, l;
    cin >> n >> k;

    int x, y;
    for (int i=0; i<k; i++) {
        cin >> x >> y;
        board[x][y] = 2; //사과 표시
    }

    queue<pair<int, char> > di; //방향 전환 정보 저장
    cin >> l;
    char ch;
    for (int i=0; i<l; i++) {
        cin >> x >> ch;
        di.push(make_pair(x, ch));
    }

    int go[][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}}; // 오른쪽, 아래, 왼쪽, 위
    int direction = 0; // 뱀의 방향, go의 행
    int ans = 0; // 정답 = 죽는 시간

    queue<pair<int, int> > snake; // 현재 뱀이 위치한 좌표 저장
    snake.push(make_pair(1,1));
    board[1][1] = 1;

    while (!snake.empty()) {
        pair<int, char> way = di.front();
        int time = way.first - ans; // 직진해야하는 시간
        di.pop();

        // 여기서 의문: 방향 전환 다 하고 직진만 하는 경우 time이 음수값인데 문제 없나?

        while (time--) {
            ans += 1;
            // 현재 뱀의 위치
            // 큐의 front가 아닌 back이 머리의 위치다
            pair<int, int> cur = snake.back();

            // 머리 이동 시작
            x = cur.first + go[direction][0];
            y = cur.second + go[direction][1];

            // 벽 만남 - 종료
            if (x < 1 || x > n || y < 1 || y > n) {
                cout << ans << "\n";
                return 0;
            }
            // 자기 자신을 만남 - 종료
            if (board[x][y] == 1) {
                cout << ans << "\n";
                return 0;
            }

            // 사과 아니면 꼬리를 땡긴다
            if (board[x][y] != 2) {
                board[snake.front().first][snake.front().second] = 0;
                snake.pop();
            }

            // 머리의 위치 저장
            snake.push(make_pair(x,y));
            board[x][y] = 1;
        }

        //방향 바꾸기
        if (way.second == 'D') direction = (direction+1) % 4;
        else if (way.second == 'L') {
            if (direction == 0) {
                direction = 3;
            }
            else {
                direction = (direction-1) % 4;
            }
        }
    }


    return 0;
}