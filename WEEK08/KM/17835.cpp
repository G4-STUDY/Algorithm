#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
using namespace std;

#define ll long long

const ll INF = 1e11;
int n, m, k;
// edge 중복제거
unordered_map<ll, bool> check;
// edge 길이저장용
unordered_map<ll, int> edgedist;
vector<int> edge[100001]; // edge[start][end]=dist;
ll dist[100001];

priority_queue<pair<ll, int>,
               vector<pair<ll, int>>,
               greater<pair<ll, int>>>
    pq;

// edge idx변환
ll parse(ll from, ll to)
{
    return (from * (ll)n) + to;
}
// 다익스트라 pq에 들어있는걸로
void dijkstra()
{
    for (int i = 1; i <= n; i++)
    {
        dist[i] = INF;
    }
    while (!pq.empty())
    {
        int cur = pq.top().second;
        ll cost = pq.top().first;
        pq.pop();
        if (dist[cur] != INF)
            continue;
        dist[cur] = cost;
        for (int next : edge[cur])
        {
            if (dist[next] != INF)
                continue;
            pq.push({cost + (ll)edgedist[parse(cur, next)], next});
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> k;
    int a, b, c;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        // idx 변환
        ll idx = parse(b, a);
        if (check[idx])
        {
            edgedist[idx] = min(edgedist[idx], c);
        }
        else
        {
            check[idx] = true;
            edge[b].push_back(a);
            edgedist[idx] = c;
        }
    }
    // 면접장들 pq에 넣기
    for (int i = 0; i < k; i++)
    {
        cin >> a;
        pq.push({0, a});
    }
    // 다익스트라
    dijkstra();

    ll ans = 0;    // 거리
    int ansi = -1; // idx
    // 가장 먼곳찾기
    for (int i = 1; i <= n; i++)
    {
        if (ans < dist[i])
        {
            ansi = i;
            ans = dist[i];
        }
    }
    // 출력
    cout << ansi << '\n'
         << ans;
    return 0;
}
/*
어떤 두 도시 사이에는 도로가 없을 수도,
여러 개가 있을 수도 있다.
또한 어떤 도시에서든 적어도 하나의 면접장까지 갈 수 있는 경로가 항상 존재한다.
---
면접장에서 다른도시로 다익스트라 하고 최소값 찾기
----
면접장마다 다익스트라 하고 비교 - 실패
그냥 면접장 pq에 다넣고 돌리기 -성공

*/