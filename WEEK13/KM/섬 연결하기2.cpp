#include <string>
#include <vector>
#include <queue>

using namespace std;

int p[101];
priority_queue<
pair<int,pair<int,int>>,
vector<pair<int,pair<int,int>>>,
greater<pair<int,pair<int,int>>>
>pq;

int find(int x)
{
    if(p[x]==x)return x;
    return p[x]=find(p[x]);
}

void myunion(int a,int b){
    if(a>b)swap(a,b);
    p[b]=a;
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    for(int i=0;i<n;i++)p[i]=i;
    for(vector<int> edge : costs)
    {
        pq.push({edge[2],{edge[0],edge[1]}});
    }
    while(!pq.empty()){
        int cost=pq.top().first;
        int a=pq.top().second.first;
        int b=pq.top().second.second;
        pq.pop();
        a=find(a);
        b=find(b);
        if(a==b) continue;
        answer+=cost;
        myunion(a,b);
    }
    return answer;
}