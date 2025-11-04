#include <iostream>
#include <vector>

using namespace std;

vector<pair<int,int>> edge;
int n,m;
int p[500001];

int find(int x){
    if(x==p[x])return x;
    return p[x]=find(p[x]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        edge.push_back({a,b});
    }
    int idx=1;
    for(int i=0;i<n;i++){
        p[i]=i;
    }
    for(pair<int,int> e:edge){
        int a=e.first;
        int b=e.second;
        a=find(a);
        b=find(b);
        if(a==b){
            cout<<idx;
            return 0;
        }
        if(a>b)swap(a,b);
        p[b]=a;
        idx++;
    }
    cout<<0;
    return 0;
}