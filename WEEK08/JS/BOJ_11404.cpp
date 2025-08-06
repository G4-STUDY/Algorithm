//플로이드 
#include<iostream>

using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    const int INF = 0x3fffffff;
    int dist[101][101]; //인덱스 1부터 -> 역 1 ~ n
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++) 
        {   
            dist[i][j] = INF;
        }
    }

    for(int i = 0; i < m; i++)
    {
        int st, en, cost;
        cin >> st >> en >> cost;
        dist[st][en] = min(dist[st][en], cost);
    }
    //같은 역에서 같은 역 가는 비용 0으로 설정
    for(int i = 1; i <= n; i++) dist[i][i] = 0;

    for(int mid = 1; mid <= n; mid++)
        for(int st = 1; st <= n; st++ )
            for(int en = 1; en <= n; en++)
            {
                //현재까지의 경로보다 mid 노드를 거쳐가는 경로가 효율적이면
                if(dist[st][en] > dist[st][mid] + dist[mid][en]) 
                {
                    //현재까지의 최단 경로를 mid 노드를 거쳐가는 경로 갱신
                    dist[st][en] = dist[st][mid] + dist[mid][en];
                }    
            }
  ;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(dist[i][j] == INF) cout << 0;
            else cout << dist[i][j];
            cout << ' ';
        }
        cout << '\n';
    }
}
