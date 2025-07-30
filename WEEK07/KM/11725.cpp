#include <iostream>
#include <vector>
using namespace std;

vector<int> edge[100001];
int p[100001];//부모노드 저장
bool visit[100001];

void dfs(int cur){
    for(int next:edge[cur]){
        if(visit[next]) continue;
        visit[next]=true;
        p[next]=cur;
        dfs(next);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    visit[1]=true;
    dfs(1);
    for(int i=2;i<=n;i++){
        cout<<p[i]<<'\n';    
    }
    return 0;
}