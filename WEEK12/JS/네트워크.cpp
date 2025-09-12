#include <string>
#include <vector>

using namespace std;

void dfs(int cur, int (&vis)[200], vector<int> (&adj)[200])
{
    for(int nxt : adj[cur])
    {
        if(vis[nxt] == 1) continue;
        vis[nxt] = 1;
        dfs(nxt, vis, adj);
        
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    //방문 배열 
    int vis[200] = { 0, };
    //인접 리스트 생성 ( 노드 번호 0 ~ n-1)
    vector<int> adj[200]; 
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(computers[i][j] == 1)
            {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    // 가능한 시작점에 대해 dfs 
    for(int cur = 0; cur < n ;cur++)
    {
        if(vis[cur] == 1) continue;
        answer++; //시작점 추가 = 네트워크 추가 
        dfs(cur, vis, adj); // i 노드를 시작점으로 dfs 
    }
    
    return answer;
}