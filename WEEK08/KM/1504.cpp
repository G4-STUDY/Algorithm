#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 1e9;
int n, e;
vector<pair<int, int>> edge[801];
int dist[801];   // 1에서 다른정점까지 거리
int distv1[801]; // v1에서 다른정점까지 거리
int distv2[801]; // v2에서 다른정점까지 거리
bool visit[801];
priority_queue<pair<int, int>, vector<pair<int, int>>,
               greater<pair<int, int>>

               >
    pq;

void dijkstra(int start)
{ // 다익스트라
    pq.push({0, start});
    while (!pq.empty())
    {
        pair<int, int> cur = pq.top();
        pq.pop();
        if (visit[cur.second])
            continue;
        visit[cur.second] = true;
        dist[cur.second] = cur.first;
        for (pair<int, int> next : edge[cur.second])
        {
            pq.push({cur.first + next.second, next.first});
        }
    }
}

void distinit(int num)
{ // visit,dist 초기화
    for (int i = 1; i <= num; i++)
    {
        visit[i] = false;
        dist[i] = INF;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> e;
    int a, b, c;
    for (int i = 0; i < e; i++)
    {
        cin >> a >> b >> c;
        edge[a].push_back({b, c});
        edge[b].push_back({a, c});
    }
    int v1, v2;
    cin >> v1 >> v2;
    // 다익스트라 v1
    distinit(n);
    dijkstra(v1);
    // distv1에 옮기기
    for (int i = 1; i <= n; i++)
    {
        distv1[i] = dist[i];
    }
    // 다익스트라 v2
    distinit(n);
    dijkstra(v2);
    for (int i = 1; i <= n; i++)
    {
        distv2[i] = dist[i];
    }
    // 다익스트라 1
    distinit(n);
    dijkstra(1);
    // ans1= 1-v1-v2-n
    // ans2= 1-v2-v1-n
    int ans1 = INF, ans2 = INF;
    if (dist[v1] != INF && distv1[v2] != INF && distv2[n] != INF) // 1-v1-v2-n
    {
        ans1 = dist[v1] + distv1[v2] + distv2[n];
    }
    if (dist[v2] != INF && distv2[v1] != INF && distv1[n] != INF) // 1-v2-v1-n
    {
        ans2 = dist[v2] + distv2[v1] + distv1[n];
    }
    // 둘다 INF면
    if (ans1 == INF && ans2 == INF)
    {
        cout << -1;
    }
    else
    {
        if (ans1 == INF)
        { // ans2만 가능
            cout << ans2;
        }
        else if (ans2 == INF)
        { // ans1만 가능
            cout << ans1;
        }
        else
        { // 둘다 가능
            cout << min(ans1, ans2);
        }
    }
    return 0;
}

/*
1-v1-v2-n
1-v2-v1-n
*/