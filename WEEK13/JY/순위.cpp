#include <string>
#include <vector>

using namespace std;

#define INF 0x3f3f3f3f

int graph[101][101];

int solution(int n, vector<vector<int>> results) {
    int answer = 0;

    for(int i=1; i<=n; i++){
        fill(graph[i], graph[i]+n+1, INF);
    }
    for(int i=1; i<=n; i++){
        graph[i][i] = 0;
    }

    for(vector<int> result : results){
        int a = result[0];
        int b = result[1];
        graph[a][b] = 1;
        graph[b][a] = -1;
    }

    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(graph[i][k]==1 && graph[k][j]==1){
                    graph[i][j] = 1;
                }
                else if(graph[i][k]==-1 && graph[k][j]==-1){
                    graph[i][j] = -1;
                }
            }
        }
    }

    bool found = true;
    for(int i=1; i<=n; i++){
        found = true;
        for(int j=1; j<=n; j++){
            if(graph[i][j] == INF) {
                found = false;
                continue;
            }
        }
        if(found) answer++;
    }

    return answer;
}