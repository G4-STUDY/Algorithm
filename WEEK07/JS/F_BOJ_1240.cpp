#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<map>
using namespace std;
void dfs(int cur, int en, int cur_dist);
int adj_matrix[1001][1001] = { 0, };
int parent[1001] = { 0, };
 int n, m;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
   
    cin >> n >> m;

   
    
    for(int i = 0; i < n - 1; i++)
    {
        int u, v ,dist;
        cin >> u >> v >> dist;
        adj_matrix[u][v] = dist;
        adj_matrix[v][u] = dist;

    }

    for(int i = 0; i < m; i++)
    {
        fill(parent, parent + 1001, 0);
        int st, en;  //시작 노드, 목표 노드
        cin >> st >> en;
        dfs(st, en, 0);
        
    }

    return 0;
}

void dfs(int cur, int en, int cur_dist)
{
  
    for(int nxt = 1; nxt <= n; nxt++)
    {
        if(adj_matrix[cur][nxt] == 0) continue; //인접안하는 노드 pass
        if(nxt == parent[cur]) continue; //부모 노드 pass
        //종료 조건 (방문 가능한 노드가 목표 노드인 경우)
        if(nxt == en) 
        {
            cur_dist += adj_matrix[cur][nxt];
            cout << cur_dist << '\n';
            return;
        }
        //방문 가능하지만 목표 노드 아닌 경우
        parent[nxt] = cur;
        cur_dist += adj_matrix[cur][nxt]; //거리 누적
        dfs(nxt, en, cur_dist); 
        cur_dist -= adj_matrix[cur][nxt]; //거리 반환(다른 경로 탐색 위함)
    }
}