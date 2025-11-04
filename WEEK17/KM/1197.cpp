#include <iostream>
#include <queue>

using namespace std;

int v,e;
vector<int> edge[10001];
priority_queue<
pair<int,pair<int,int>>,
vector<pair<int,pair<int,int>>>,
greater<pair<int,pair<int,int>>>
>pq;

int p[100001];

int find(int x){
    if(x==p[x])return x;
    return p[x]=find(p[x]);
}

int main()
{
    int ans=0;
    cin>>v>>e;
    for(int i=0;i<e;i++){
        int a,b,c;
        cin>>a>>b>>c;
        pq.push({c,{a,b}});
    }
    for(int i=1;i<=v;i++){
        p[i]=i;
    }
    while(!pq.empty()){
        int cost=pq.top().first;
        int a=pq.top().second.first;
        int b=pq.top().second.second;
        pq.pop();
        a=find(a);
        b=find(b);
        if(a==b)continue;
        if(a>b)swap(a,b);
        p[b]=a;
        ans+=cost;
    }
    cout<<ans;
    return 0;
}