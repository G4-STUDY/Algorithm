#include <iostream>
#include <vector>

using namespace std;

const long long INF = 1e10;
int n, m;
long long dist[501]; // n*m*w -30억까지 커버해야됌
vector<pair<pair<int, int>, int>> bus;

bool bellmanford(int start)
{
    dist[start] = 0;
    for (int i = 0; i < n - 1; i++)
    { // n-1번 돌리기
        for (pair<pair<int, int>, int> b : bus)
        {
            int cur = b.first.first;
            int next = b.first.second;
            int cost = b.second;
            if (dist[cur] == INF)
                continue;
            if (dist[next] > dist[cur] + cost)
            {
                dist[next] = dist[cur] + cost;
            }
        }
    }
    // 음의 사이클 확인
    for (pair<pair<int, int>, int> b : bus)
    {
        int cur = b.first.first;
        int next = b.first.second;
        int cost = b.second;
        if (dist[cur] == INF)
            continue;
        if (dist[next] > dist[cur] + cost)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        bus.push_back({{a, b}, c});
    }
    for (int i = 1; i <= n; i++)
        dist[i] = INF;
    if (bellmanford(1))
    {
        for (int i = 2; i <= n; i++)
        {
            if (dist[i] == INF)
                cout << -1 << '\n';
            else
                cout << dist[i] << '\n';
        }
    }
    else
    {
        cout << -1;
    }
    return 0;
}