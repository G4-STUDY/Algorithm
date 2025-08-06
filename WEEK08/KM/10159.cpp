/*
dfs 2번
#include <iostream>
#include <unordered_map>
#include <vector>
#include <cstring>
using namespace std;

int n,m;
unordered_map<int,bool> mset; //몇개인지 확인용
vector<int> gedge[101];
vector<int> ledge[101];
bool visit[101];

void gdfs(int cur){ // dfs1
    for(int next:gedge[cur]){
        if(visit[next])continue;
        mset[next]=true;//개수확인용
        visit[next]=true;
        gdfs(next);
    }
}
void ldfs(int cur){ // dfs2
    for(int next:ledge[cur]){
        if(visit[next])continue;
        mset[next]=true;//개수확인용
        visit[next]=true;
        ldfs(next);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n>>m;
    int a,b;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        gedge[b].push_back(a); //b>a
        ledge[a].push_back(b); //a<b
    }
    for(int i=1;i<=n;i++){
        mset.clear();
        mset[i]=true;
        memset(visit,false,sizeof(visit));
        visit[i]=true;
        gdfs(i);// i>? 확인
        memset(visit,false,sizeof(visit));
        visit[i]=true;
        ldfs(i);// i<? 확인
        cout<<n-mset.size()<<'\n';
    }
    return 0;
}
*/
/*
1 2 3 4 5 6
1<2
2<3
3<4
5<4
6<5

1 2 3 4 5?6?
1 2 3 4 5 5?6?
1 2 3 4 5?6?

1<2<3<4
6<5<4

작은쪽 그래프 탐색
큰쪽 그래프 탐색
visit[]false 개수세기

*/
#include <iostream>

using namespace std;

bool visit[101][101];
int n, m;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    int a, b;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        visit[a][b] = true;
    }
    // 플로이드
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int k = 1; k <= n; k++)
            {
                if (visit[j][i] && visit[i][k])
                    visit[j][k] = true;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        int cnt = 0;
        for (int j = 1; j <= n; j++)
        {
            // 내가 방문했거나 나를 방문했거나
            if (visit[i][j] || visit[j][i])
                cnt++;
        }
        cout << n - cnt - 1 << '\n'; //-1 나자신
    }
    return 0;
}

/*
floyd 시간복잡도 O(N^3)
노드마다 bfs 시간복잡도 O(N*(N*M))
문제 조건 5<N<100 0<M<2000
floyd 승.
배열기반 접근으로 캐시효율성 높고 오버헤드가 적음
bfs는 큐에삽입과 삭제하는연산등등 오버헤드가 더크기도 함
*/