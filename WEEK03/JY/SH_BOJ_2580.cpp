// 2580 스도쿠

#include <iostream>
#include <vector>
using namespace std;

int board[9][9];
vector<pair<int, int> > blank;

void func(int idx) {
    // 벡터에 저장된 빈칸을 모두 채웠으면 출력하고 종료
    if (idx == blank.size()) {
        for (int i=0; i<9; i++) {
            for (int j=0; j<9; j++) {
                cout << board[i][j] << " ";
            }
            cout << "\n";
        }
        exit(0);
    }

    // 해당 좌표에 들어갈 수 있는 후보를 저장하기 위한 배열
    // 0 - 이미 있음, 1 - 들어갈 수 있음
    int hubo[10];
    fill(hubo, hubo+10, 1);

    int x = blank[idx].first;
    int y = blank[idx].second;

    // 가로 검사
    for (int i=0; i<9; i++) {
        hubo[board[x][i]] = 0;
    }
    // 세로 검사
    for (int i=0; i<9; i++) {
        hubo[board[i][y]] = 0;
    }
    // 3*3 네모 검사
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            hubo[board[(x/3)*3 + i][(y/3)*3 + j]] = 0;
        }
    }

    // 들어갈 수 있는 수로 백트래킹
    for (int i=1; i<=9; i++) {
        if (hubo[i] == 0) continue;
        board[x][y] = i;
        func(idx+1);
        board[x][y] = 0;
    }

}

int main() {
    // 입력받으면서 비어 있는 칸의 좌표를 벡터에 저장
    for (int i=0; i<9; i++) {
        for (int j=0; j<9; j++) {
            cin >> board[i][j];
            if (board[i][j] == 0) {
                blank.push_back(make_pair(i, j));
            }
        }
    }

    func(0);

}
