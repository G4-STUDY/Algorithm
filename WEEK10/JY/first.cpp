#include <bits/stdc++.h>
using namespace std;

void readInput(int &n, vector<array<int,4>> &graph, int &r, vector<int> &record);
void printInput(int n, const vector<array<int,4>> &graph, int r, const vector<int> &record);

vector<pair<int,int>> solution( const vector<array<int,4>>& graph, const vector<int>& record) {
    vector<pair<int,int>> answer;
    // 여기에 코드 구현

    return answer;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, r; // 도로 수, 주행 경로 원소 수
    vector<array<int,4>> graph;
    vector<int> record;

    readInput(n, graph, r, record); // 입력
    //printInput(n, graph, r, record); // 출력 (입력 확인용)

    auto result = solution(graph, record);
    for (auto &p : result) {
        cout << p.first << " " << p.second << "\n";
    }

    return 0;
}

void readInput(int &n, vector<array<int,4>> &graph, int &r, vector<int> &record) {
    cin >> n;
    graph.resize(n);
    for (int i = 0; i < n; i++) {
        int u, v, w, c;
        cin >> u >> v >> w >> c;
        graph[i] = {u, v, w, c};
    }
    cin >> r;
    record.resize(r);
    for (int i = 0; i < r; i++) cin >> record[i];
}

void printInput(int n, const vector<array<int,4>> &graph, int r, const vector<int> &record) {
    cout << "n = " << n << "\n";
    cout << "graph:\n";
    for (auto &g : graph) {
        cout << g[0] << " " << g[1] << " " << g[2] << " " << g[3] << "\n";
    }
    cout << "r = " << r << "\n";
    cout << "record:\n";
    for (auto &val : record) {
        cout << val << " ";
    }
    cout << "\n";
}

/** 예제 1

9
1 2 3 1
1 5 4 2
1 6 7 4
1 3 4 3
2 4 1 2
2 5 5 4
3 6 2 1
2 5 4 1
5 6 5 3
3
1 -4 2

 */

/** 예제 2

6
1 2 3 2
1 5 2 1
2 3 4 1
2 5 4 3
3 4 5 3
3 5 7 2
4
2 -3 2 -1

 */