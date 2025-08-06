#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 200001;

int v, e;
int st;
priority_queue<pair<int, int>,
               vector<pair<int, int>>,
               greater<pair<int, int>>>
    pq;

vector<pair<int, int>> edge[200001];
int dist[20001];
bool visit[200001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> v >> e;
    cin >> st;
    int a, b, c;
    for (int i = 0; i < e; i++)
    {
        cin >> a >> b >> c;
        edge[a].push_back({b, c});
    }
    for (int i = 1; i <= v; i++)
    {
        dist[i] = INF;
    }
    dist[st] = 0;
    pq.push({0, st});
    // 서로 다른 두 정점 사이에 여러 개의 간선이 존재할 수도 있음에 유의한다.
    // 다익스트라
    while (!pq.empty())
    {
        pair<int, int> cur = pq.top();
        pq.pop(); // cur={w,v}
        if (visit[cur.second])
            continue;
        visit[cur.second] = true;
        dist[cur.second] = cur.first;
        for (pair<int, int> next : edge[cur.second])
        { // next={v,w}
            pq.push({cur.first + next.second, next.first});
        }
    }
    for (int i = 1; i <= v; i++)
    {
        if (dist[i] != INF)
        {
            cout << dist[i] << '\n';
        }
        else
        {
            cout << "INF\n";
        }
    }
    return 0;
}