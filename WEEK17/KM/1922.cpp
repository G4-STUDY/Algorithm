#include <iostream>
#include <queue>
using namespace std;

int n, m;
int a, b, c;
int p[1001];
int ans = 0;
priority_queue<
    pair<int, pair<int, int>>,
    vector<pair<int, pair<int, int>>>,
    greater<pair<int, pair<int, int>>>>
    pq;
int find(int x)
{
    if (p[x] == x)
        return x;
    return p[x] = find(p[x]);
}

bool isunion(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a == b)
    {
        return true;
    }
    return false;
}

void myunion(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a == b)
        return;
    if (a > b)
        swap(a, b);
    p[b] = a;
}

int main()
{
    cin >> n;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        if (a != b)
            pq.push({c, {a, b}});
    }
    for (int i = 1; i <= n; i++)
    {
        p[i] = i;
    }
    while (!pq.empty())
    {
        int cost = pq.top().first;
        int a = pq.top().second.first;
        int b = pq.top().second.second;
        pq.pop();
        if (!isunion(a, b))
        {
            myunion(a, b);
            ans += cost;
        }
    }
    cout << ans;
    return 0;
}