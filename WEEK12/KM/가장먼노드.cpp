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
int dist[20001];
vector<int> edges[20001];

unordered_map<int,int> m;
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
    pq.push({0,1});
    int mx=0;
    while(!pq.empty()){
        if(cnt==n)break;
        int cur=pq.top().second;
        int d=pq.top().first;
        pq.pop();
        if(dist[cur]!=-1)continue;
        mx=d;
        dist[cur]=d;
        m[d]++;
        cnt++;
        for(int next:edges[cur]){
            if(dist[next]==-1)
                pq.push({d+1,next});
        }
    }
    answer=m[mx];
    return answer;
}