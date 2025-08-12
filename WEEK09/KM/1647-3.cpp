#include <iostream>
#include <queue>
using namespace std;

int p[100001];
priority_queue<
pair<int,pair<int,int>>,
vector<pair<int,pair<int,int>>>,
greater<pair<int,pair<int,int>>>
>pq;
int mxcost;
int answer=0;
int find(int x){
    if(x==p[x])return x;
    return p[x]=find(p[x]);
}

void myunion(int a, int b){
    if(b<a)swap(a,b);
    p[b]=a;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        p[i]=i;
    }
    while(m--){
        int a,b,c;
        cin>>a>>b>>c;
        pq.push({c,{a,b}});
    }
    while (!pq.empty())
    {
        int cost=pq.top().first;
        int a=pq.top().second.first;
        int b=pq.top().second.second;
        pq.pop();
        a=find(a);
        b=find(b);
        if(a==b)continue;
        myunion(a,b);
        answer+=cost;
        //마지막값 갱신
        mxcost=cost;
    }
    //마지막 제일큰값 빼기 
    cout<<answer-mxcost;
    return 0;
}