#include <bits/stdc++.h>
using namespace std;

void readInput(int &n, vector<array<int, 4>> &graph, int &r, vector<int> &record);
void printInput(int n, const vector<array<int, 4>> &graph, int r, const vector<int> &record);

/*
출발지 전부 넣고
하나씩 갈때마다
//map <유도선,bool> m[출발노드] 저장
map <유도선,경로> m[출발노드] 저장
경로 =0이면 유도선 없는거임

record 유도선 가지고 있는지확인 - bool 사용

// a - b 의 도로가 하나밖에 없나?
// 유도색깔만 다른 두개가 있으면 어쩌지
// 유도색깔이 다른데 최소값이 아니면 무조건 - 경로

// 해당경로 도로가 있는지 체크하고
// 이미 있는거면 가중치 체크하고 현재 가중치보다 작은지 큰지 검사
// go [출발지][유도선]=도착지
// isless [출발지][도착지]=유도선색깔(최소값)
// e=몇이지.. 1000이라고 가정할까..?

// 출발지-v1-v2....-도착지
// 조합들 여러개 나옴
// 여기서 조합들이 유효한지 검사하기?
// + - 가 맞는지?
// 어떻게 검사하게..? n이 1000인데..?
// 조합의 수가 적나..? edge가 적나..?
// edge가 적으면 dijkstra 하면되나
// 어처피 한번 경로 벗어나면 시작지점 바껴서
// 또 dijkstra해야되는데 최악일땐
// recode 길이만큼 dijkstra해야되는데
n=100입니다...
플로이드로 검사하자

*/
int maxn = 0;
const int INF = 1e9;
int dist[101][101]; // dist[출발][도착]=비용
int go[101][101];   // go[출발][유도선]=도착지 (도착지가 0 이면 유도선없음)
int path[101];
vector<pair<int, int>> solution(const vector<array<int, 4>> &graph, const vector<int> &record)
{
    vector<pair<int, int>> answer;
    // 여기에 코드 구현
    for (int i = 1; i <= 100; i++)
    {
        for (int j = 1; j <= 100; j++)
        {
            if (i == j)
                continue;
            dist[i][j] = INF;
        }
    }
    for (array<int, 4> arr : graph)
    {
        int a = arr[0];
        int b = arr[1];
        int w = arr[2];
        int num = arr[3]; // 유도선 색깔

        dist[a][b] = w;
        dist[b][a] = w;
        // 유도선 도착지 저장
        go[a][num] = b;
        go[b][num] = a;
        // 최대 n 저장용...
        maxn = max(maxn, a);
        maxn = max(maxn, b);
    }
    // floyd
    for (int i = 1; i <= maxn; i++)
    {
        for (int j = 1; j <= maxn; j++)
        {
            for (int k = 1; k <= maxn; k++)
            {
                if (j == k)
                    continue;
                dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
            }
        }
    }
    for (int i = 1; i <= maxn; i++)
    { // n마다 레코드 찾기
        int cur = i;
        bool flag = true;
        path[0] = cur;
        int idx = 1;
        cout << "path\n";
        cout << cur << ' ';
        for (int Udo : record)
        {
            int next = go[cur][abs(Udo)];
            if (next == 0)
            {
                flag = false;
                break;
            }
            cur = next;
            cout << cur << ' ';
            path[idx++] = cur;
        }
        cout << '\n';
        if (!flag)
            continue;
        // 목적지를 지나더라도 기록은 계속된다.
        // 목적지는 계속 바꿔야돼..?
        for (int dest = 1; dest < maxn; dest++)
        {
            cout << "checking \n";

            flag = true;
            for (int j = 0; j < idx - 1; j++)
            {
                cur = path[j];
                cout << cur << ' ';
                int next = path[j + 1];
                if (dist[cur][dest] == dist[cur][next] + dist[next][dest]) // 최단거리면
                {
                    if (record[j] < 0) // 음수면
                    {
                        flag = false;
                        break;
                    }
                }
                else
                {                      // 최단거리가 아니면
                    if (record[j] > 0) // 양수면
                    {
                        flag = false;
                        break;
                    }
                }
                cur = next;
            }
            cout << '\n';
            if (flag)
            {
                answer.push_back({i, dest});
            }
        }
    }
    cout << '\n';
    return answer;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, r; // 도로 수, 주행 경로 원소 수
    vector<array<int, 4>> graph;
    vector<int> record;

    readInput(n, graph, r, record); // 입력
    // printInput(n, graph, r, record); // 출력 (입력 확인용)

    auto result = solution(graph, record);
    for (auto &p : result)
    {
        cout << p.first << " " << p.second << "\n";
    }

    return 0;
}

void readInput(int &n, vector<array<int, 4>> &graph, int &r, vector<int> &record)
{
    cin >> n;
    graph.resize(n);
    for (int i = 0; i < n; i++)
    {
        int u, v, w, c;
        cin >> u >> v >> w >> c;
        graph[i] = {u, v, w, c};
    }
    cin >> r;
    record.resize(r);
    for (int i = 0; i < r; i++)
        cin >> record[i];
}

void printInput(int n, const vector<array<int, 4>> &graph, int r, const vector<int> &record)
{
    cout << "n = " << n << "\n";
    cout << "graph:\n";
    for (auto &g : graph)
    {
        cout << g[0] << " " << g[1] << " " << g[2] << " " << g[3] << "\n";
    }
    cout << "r = " << r << "\n";
    cout << "record:\n";
    for (auto &val : record)
    {
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
4 5 4 1
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