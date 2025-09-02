#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

priority_queue<pair<int,int>,
vector<pair<int,int>>,
greater<pair<int,int>>
>pq;
int dist[20001];          //1에서의 거리
vector<int> edges[20001]; //edge[a]=b //a->b 간선
unordered_map<int,int> m; //m[거리]=개수 해당거리인 노드개수
int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    for(int i=1;i<=n;i++){
        dist[i]=-1;
        vector<int> tmp;
    }
    for(vector<int> v:edge){
        int a=v[0];
        int b=v[1];
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    int cnt=0;
    pq.push({0,1});//0거리,1번노드 넣기
    int mx=0;
    //dijkstra
    while(!pq.empty()){
        if(cnt==n)break;
        int cur=pq.top().second;
        int d=pq.top().first;
        pq.pop();
        if(dist[cur]!=-1)continue;
        //최대값 갱신
        mx=d;
        dist[cur]=d;
        m[d]++;
        cnt++;
        for(int next:edges[cur]){
            if(dist[next]==-1)//처음방문하는노드면
                pq.push({d+1,next});
        }
    }
    answer=m[mx];//최대값노드의 개수
    return answer;
}