#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

#define X first
#define Y second

int N, M;
int cctv_cnt;
int map[10][10];
int cctv_list[10]; // i번째에 cctv 종류가 저장됨
pair <int, int> cctv_pos_list[10]; // i번째에 cctv 좌표가 저장됨
int view_dir[6] = { 0,4,2,4,4,1 }; // i번 cctv가 몇 방향을 볼 수 있는지
int see;
int min_value = 64;

void PRINTMAP(){
    for (int u = 1; u <= N; u++) {
        for (int v = 1; v <= M; v++) {
            cout << map[u][v] << ' ';
        }
        cout << '\n';
    }
}
int Counter() {
    int Count = 0;
    for (int u = 1; u <= N; u++) {
        for (int v = 1; v <= M; v++) {
            if (map[u][v] == 0) Count++;
        }
    }
    return Count;
}

void WATCH_RIGHT(int x, int y) {
    while (true) {
        int nx = x;
        int ny = y++;
        if (ny > M || map[nx][ny] == 6) return;
        if (map[nx][ny] > 0 && map[nx][ny] < 6) continue;
        map[nx][ny] -= see;
    }
}
void WATCH_LEFT(int x, int y) {
    while (true) {
        int nx = x;
        int ny = y--;
        if (ny < 1 || map[nx][ny] == 6) return;
        if (map[nx][ny] > 0 && map[nx][ny] < 6) continue;
        map[nx][ny] -= see;
    }
}
void WATCH_UP(int x, int y) {
    while (true) {
        int nx = x--;
        int ny = y;
        if (nx < 1 || map[nx][ny] == 6) return;
        if (map[nx][ny] > 0 && map[nx][ny] < 6) continue;
        map[nx][ny] -= see;
    }
}
void WATCH_DOWN(int x, int y) {
    while (true) {
        int nx = x++;
        int ny = y;
        if (nx > M || map[nx][ny] == 6) return;
        if (map[nx][ny] > 0 && map[nx][ny] < 6) continue;
        map[nx][ny] -= see;
    }
}

void CCTV_1(int cnt, int dir) {
    int x = cctv_pos_list[cnt].X;
    int y = cctv_pos_list[cnt].Y;
    switch (dir) {
        case 1:
            WATCH_RIGHT(x, y);
            break;
        case 2:
            WATCH_LEFT(x, y);
            break;
        case 3:
            WATCH_UP(x, y);
            break;
        case 4:
            WATCH_DOWN(x, y);
            break;
    }
}
void CCTV_2(int cnt, int dir) {
    int x = cctv_pos_list[cnt].X;
    int y = cctv_pos_list[cnt].Y;
    switch (dir) {
        case 1:
            WATCH_RIGHT(x, y);
            WATCH_LEFT(x, y);
            break;
        case 2:
            WATCH_UP(x, y);
            WATCH_DOWN(x, y);
            break;
    }
}
void CCTV_3(int cnt, int dir) {
    int x = cctv_pos_list[cnt].X;
    int y = cctv_pos_list[cnt].Y;
    switch (dir) {
        case 1:
            WATCH_RIGHT(x, y);
            WATCH_UP(x, y);
            break;
        case 2:
            WATCH_LEFT(x, y);
            WATCH_UP(x, y);
            break;
        case 3:
            WATCH_RIGHT(x, y);
            WATCH_DOWN(x, y);
            break;
        case 4:
            WATCH_LEFT(x, y);
            WATCH_DOWN(x, y);
            break;
    }
}
void CCTV_4(int cnt, int dir) {
    int x = cctv_pos_list[cnt].X;
    int y = cctv_pos_list[cnt].Y;
    switch (dir) {
        case 1:
            WATCH_LEFT(x, y);
            WATCH_UP(x, y);
            WATCH_DOWN(x, y);
            break;
        case 2:
            WATCH_RIGHT(x, y);
            WATCH_UP(x, y);
            WATCH_DOWN(x, y);
            break;
        case 3:
            WATCH_RIGHT(x, y);
            WATCH_LEFT(x, y);
            WATCH_DOWN(x, y);
            break;
        case 4:
            WATCH_RIGHT(x, y);
            WATCH_LEFT(x, y);
            WATCH_UP(x, y);
            break;
    }
}
void CCTV_5(int cnt, int dir) {
    int x = cctv_pos_list[cnt].X;
    int y = cctv_pos_list[cnt].Y;
    WATCH_RIGHT(x, y);
    WATCH_LEFT(x, y);
    WATCH_UP(x, y);
    WATCH_DOWN(x, y);
}

void CCTV(int cnt, int dir) {
    switch (cctv_list[cnt]) {
        case 1:
            CCTV_1(cnt, dir);
            break;
        case 2:
            CCTV_2(cnt, dir);
            break;
        case 3:
            CCTV_3(cnt, dir);
            break;
        case 4:
            CCTV_4(cnt, dir);
            break;
        case 5:
            CCTV_5(cnt, dir);
            break;
    }
}

void Gamsi(int cctv_num, int cnt) {
    int view_cnt = view_dir[cctv_num];
    if (cnt > cctv_cnt) {
        if (Counter() < min_value) min_value = Counter();
        return;
    }

    for (int v = 1; v <= view_cnt; v++) {
        see = 1;
        CCTV(cnt, v);
        Gamsi(cctv_list[cnt + 1], cnt + 1);
        see = -1;
        CCTV(cnt, v);
    }
}

int main(void) {
    cin >> N >> M;
    for (int u = 1; u <= N; u++) {
        for (int v = 1; v <= M; v++) {
            cin >> map[u][v];
            if (map[u][v] > 0 && map[u][v] < 6) {
                cctv_list[++cctv_cnt] = map[u][v];
                cctv_pos_list[cctv_cnt] = { u, v };
            }
        }
    }

    Gamsi(cctv_list[1], 1);
    cout << min_value;

    return 0;
}
