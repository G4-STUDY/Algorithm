#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>

using namespace std;

/**
 * flip -> 앞 절만 잘라서 뒤에 붙임
 * shuffle -> 상부부터 번갈아서 한장씩
 *
 * 상부큐, 하부큐 나누고 flip 이면 상부에 넣기만하고
 * 셔플이면 섞고
 */

queue<int> q;
queue<int> front;
queue<int> back;
vector<int> ans;

void solution(vector<int> cards, int n, vector<string> command) {

    int mid = n / 2;

    for (int card : cards) {
        q.push(card);
    }

    for (string com : command) {

        for (int i=0; i < mid; i++) {
            front.push(q.front());
            q.pop();
        }

        for (int i=0; i < mid; i++) {
            back.push(q.front());
            q.pop();
        }

        if (com == "flip") {
            while (!back.empty()) {
                q.push(back.front());
                back.pop();
            }
            while (!front.empty()) {
                q.push(front.front());
                front.pop();
            }
        }
        else if (com == "shuffle") {
            for (int i=0; i < mid; i++) {
                q.push(front.front());
                front.pop();

                q.push(back.front());
                back.pop();
            }
        }
    }

    while (!q.empty()) {
        ans.push_back(q.front());
        q.pop();
    }

}

// ====== Local runner (입력/출력만 담당) ======
// 입력 형식 (로컬 테스트용):
// n
// cards[0] cards[1] ... cards[n-1]
// m
// command[0]
// command[1]
// ...
// command[m-1]
//
// 출력: 명령 모두 적용 후 카드 배열 (공백 구분)
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;
    vector<int> cards(n);
    for (int i = 0; i < n; ++i) cin >> cards[i];

    int m; cin >> m;
    vector<string> command(m);
    for (int i = 0; i < m; ++i) cin >> command[i];

    solution(cards, n, command);

    for (int i = 0; i < (int)ans.size(); ++i) {
        if (i) cout << ' ';
        cout << ans[i];
    }
    cout << "\n";
    return 0;
}

/*
8
1 2 3 4 5 6 7 8
4
shuffle
flip
flip
shuffle
 */