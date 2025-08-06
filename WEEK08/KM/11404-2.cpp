#include <iostream>

using namespace std;
const int INF = 1e9;
int n, m;
int bus[101][101];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    // bus 초기화
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            bus[i][j] = INF;
    }
    int a, b, c;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        // 버스가 하나가 아니면 최소값으로
        bus[a][b] = min(bus[a][b], c);
    }
    // 플로이드
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            for (int k = 1; k <= n; k++)
            {
                if (j == k)
                    continue;
                bus[j][k] = min(bus[j][k], bus[j][i] + bus[i][k]);
            }
    }
    // 출력
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (bus[i][j] == INF)
                cout << 0 << ' ';
            else
                cout << bus[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}