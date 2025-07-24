#include <iostream>
#include <map>
#include <queue>

using namespace std;

priority_queue <pair<int, int>> hard_q;
priority_queue <pair<int, int>> easy_q;
map <int, int> m;

int N, M;
int p_num, p_rank;
string command;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    for (int u = 0; u < N; u++) {
        cin >> p_num >> p_rank;
        hard_q.push({ p_rank, p_num });
        easy_q.push({ -p_rank, -p_num });
        m[p_num] = p_rank;
    }

    cin >> M;
    for (int u = 0; u < M; u++) {
        cin >> command >> p_num;
        if (command == "add") {
            cin >> p_rank;
            hard_q.push({ p_rank, p_num });
            easy_q.push({ -p_rank, -p_num });
            m[p_num] = p_rank;
        }
        else if (command == "solved") {
            m[p_num] = 0;
        }
        else if (p_num == 1) {
            while (m[hard_q.top().second] != hard_q.top().first) hard_q.pop();
            cout << hard_q.top().second << '\n';
        }
        else {
            while (m[-easy_q.top().second] != -easy_q.top().first) easy_q.pop();
            cout << -easy_q.top().second  <<'\n';
        }
    }
    return 0;
}