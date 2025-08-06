//저울 
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> adj[101];
    int n;
    int m;
    cin >> n;
    cin >> m;

    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[v].push_back(u);
    }
    //각 물건에 대해 
    for(int i = 1; i <= n; i++){
        int result = 0;
        
        int vis[101];
        fill(vis, vis + 101, 0);
        // i에서 시작시 방문 가능한 노드 수 찾기 
        queue<int> q;
        q.push(i);
        vis[i] = 1;
        while(!q.empty())
        {
            int cur = q.front(); q.pop();
            for(int nxt : adj[cur])
            {
                if(vis[nxt] == 1) continue;
                q.push(nxt);
                vis[nxt] = 1;
                result ++;
            }
        }
        // i가 아닌 노드에서 시작 시 i를 방문하는 경우 찾기 
        for(int j = 1; j <= n; j++){
            if(j == i) continue;
            fill(vis, vis + 101, 0);
            queue<int> q;
            q.push(j);
            vis[j] = 1;
            bool flag = true;
            while(!q.empty())
            {
                int cur = q.front(); q.pop();
                for(int nxt : adj[cur])
                {
                    if(nxt == i)
                    {
                        result++;
                        flag = false;
                        break;
                    }
                    if(vis[nxt] == 1) continue;
                    q.push(nxt);
                    vis[nxt] = 1;
                }
                if(flag == false) break;
            }
            
        }

        cout << (n - 1) - result << '\n';
        
    }

}