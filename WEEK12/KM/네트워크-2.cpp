#include <string>
#include <vector>

using namespace std;

vector<vector<int>> edge;
bool visit[201];

void dfs(int cur){
    for(int next=0;next<edge[cur].size();next++){
        if(edge[cur][next]==0)continue;
        if(visit[next])continue;
        visit[next]=true;
        dfs(next);
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    edge=computers;
    for(int i=0;i<n;i++){
        if(visit[i])continue;
        answer++;
        visit[i]=true;
        dfs(i);
    }
    return answer;
}