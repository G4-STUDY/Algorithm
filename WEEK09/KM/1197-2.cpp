#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int v,e;
priority_queue<pair<int,pair<int,int>>,
vector<pair<int,pair<int,int>>>,
greater<pair<int,pair<int,int>>>
> pq;
int p[10001];
/*
가중치가 -2,147,483,648보다 크거나 같고, 2,147,483,647
음수간선도 있으니까 long long 하자
*/
long long answer=0;


int find(int x){
    if(x==p[x])return x;
    return p[x]=find(p[x]);
}

void myunion(int a,int b)
{
    if(b<a)swap(a,b);
    p[b]=a;
}
int main()
{
    cin>>v>>e;
    for(int i=1;i<=v;i++)p[i]=i;
    for(int i=0;i<e;i++){
        int a,b,c;
        cin>>a>>b>>c;
        pq.push({c,{a,b}});
    }
    while(!pq.empty()){
        long long cost=pq.top().first;
        int a=pq.top().second.first;
        int b=pq.top().second.second;
        pq.pop();
        a=find(a);
        b=find(b);
        //같은집합이면 continue
        if(a==b)continue;
        //union(a,b) 했으니까 answer+=cost하기
        myunion(a,b);
        answer+=cost;    
    }
    cout<<answer;
    return 0;
}
