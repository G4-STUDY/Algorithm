#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define INF 0x3F3F3F3F

priority_queue<int> pq;
int dist[20001];
vector<int> graph[20001];

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;

    fill(dist, dist+20001, INF);

    for(vector<int> e : edge){
        graph[e[0]].push_back(e[1]);
        graph[e[1]].push_back(e[0]);
    }

    dist[1] = 0;
    for(int v : graph[1]){
        pq.push(v);
        dist[v] = 1;
    }

    while(!pq.empty()){
        int cur = pq.top();
        pq.pop();

        for(int v : graph[cur]){
            if(dist[v] > dist[cur] + 1){
                dist[v] = dist[cur] + 1;
                pq.push(v);
            }
        }
    }

    int maxVal = -1;
    for(int i=1; i<=n; i++){
        if(dist[i] == INF) continue;
        maxVal = max(dist[i], maxVal);
    }

    for(int i=1; i<=n; i++){
        if(dist[i] == maxVal) answer++;
    }

    return answer;
}

/**
다익스트라 - 각 노드까지의 최단 거리를 구한다


*/