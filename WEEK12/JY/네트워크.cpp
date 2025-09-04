#include <string>
#include <vector>
#include <queue>

using namespace std;

queue<int> q;
int vis[201];

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(computers[i][j] == 0 || vis[i] == 1) continue;

            q.push(i);
            vis[i] = 1;

            while(!q.empty()){
                int cur = q.front();
                q.pop();

                for(int k=0; k<n; k++){
                    if(computers[cur][k] == 1 && vis[k] == 0){
                        q.push(k);
                        vis[k] = 1;
                    }
                }
            }
            answer += 1;

        }
    }


    return answer;
}