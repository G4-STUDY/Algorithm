#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

int n, m;
unordered_map<int, int> level;
unordered_map<int, bool> check;
priority_queue<pair<int, int>> pq;
priority_queue<pair<int, int>, vector<pair<int, int>>,
               greater<pair<int, int>>>
    pq2;

int highpop()
{
    while (!check[pq.top().second] || level[pq.top().second] != pq.top().first)
    {
        pq.pop();
    }
    int result = pq.top().second;
    return result;
}

int lowpop()
{
    while (!check[pq2.top().second] || level[pq2.top().second] != pq2.top().first)
    {
        pq2.pop();
    }
    int result = pq2.top().second;
    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    int p, l;
    for (int i = 0; i < n; i++)
    {
        cin >> p >> l;
        pq.push({l, p});
        pq2.push({l, p});
        check[p] = true;
        level[p] = l;
    }
    cin >> m;
    string s;
    int a;
    for (int i = 0; i < m; i++)
    {
        cin >> s;
        if (s == "recommend")
        {
            cin >> a;
            if (a == 1)
            {
                // 어려운문제
                cout << highpop() << '\n';
            }
            else
            {
                // 쉬운문제
                cout << lowpop() << '\n';
            }
        }
        else if (s == "add")
        {
            cin >> p >> l;
            pq.push({l, p});
            pq2.push({l, p});
            check[p] = true;
            level[p] = l;
        }
        else
        {
            cin >> a;
            check[a] = false;
        }
    }
    return 0;
}