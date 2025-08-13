#include <iostream>

using namespace std;

int p[1001];
int t;
int n,m;

int find(int x){
    if(x==p[x]) return x;
    return p[x]=find(p[x]);
}

void myunion(int a,int b){
    if(b<a)swap(a,b);
    p[b]=a;
}

int main()
{
    cin>>t;
    while(t--){
        int answer=0;
        cin>>n>>m;
        for(int i=1;i<=n;i++)p[i]=i;
        while(m--){
            int a,b;
            cin>>a>>b;
            a=find(a);
            b=find(b);
            if(a==b) continue;
            myunion(a,b);
            answer++;
        }
        cout<<answer<<'\n';
    }
    return 0;
}