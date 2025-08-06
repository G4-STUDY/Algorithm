//저울 - 플로이드 풀이 
#include<iostream>
#include<vector>
using namespace std;

bool graph[101][101]; //graph[st][en] == true -> st에서 en으로 가는 경로 존재

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m; 
    cin >> n >> m; 
    
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v; 
        graph[v][u] = true;
    }
    
    for(int mid = 1; mid <= n; mid++){
        for(int st = 1; st <= n; st++){
            for(int en = 1; en <= n; en++){
                if(graph[st][en] == true) continue; //이미 방문 가능하면 pass
                //현재까지(mid를 방문하는 케이스 고려 x) 방문 불가능했는데  mid를 통해 방문 가능하면 방문 가능  
                if(graph[st][mid] && graph[mid][en]){
                    graph[st][en] = true;
                }
            }
        }
    }
    

    for(int i = 1; i <= n; i++){
        int can_know = 0;
        for(int j = 1; j <= n; j++){
            if(graph[i][j] == true) can_know++; // i에서 i가 아닌 노드 j로의 경로 있다면 방문 가능 노드 증가 
            if(graph[j][i] == true) can_know++; // i가 아닌 노드 j에서 i로의 경로 있다면 방문 가능 노드 증가 
        }

        //cout << (n - 1) - can_know - 1 << '\n';
        cout << (n - 1) - can_know  << '\n';
    }
}