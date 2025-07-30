#include <iostream>
using namespace std;
int edge[100001][2];
int cnt;
int depth;
void dfs(int cur){ //전부탐색하고 루트로 돌아오기까지
    if(edge[cur][0]!=0){
        dfs(edge[cur][0]);
        cnt+=2;
    }
    if(edge[cur][1]!=0){
        dfs(edge[cur][1]);
        cnt+=2;
    }
}

void dfs2(int cur){ //오른쪽으로 내려가기만
    if(edge[cur][1]!=0){
        depth++;
        dfs2(edge[cur][1]);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int a,b,c;
        cin>>a>>b>>c;
        if(b==-1)b=0; //0으로 전처리
        if(c==-1)c=0; //0으로 전처리
        edge[a][0]=b; //왼쪽자식
        edge[a][1]=c; //오른쪽 자식
    }
    cnt=0;
    dfs(1);
    depth=0;
    dfs2(1);
    cout<<cnt-depth;
    return 0;
}

/*
루트는 1

dfs(왼쪽)
나
dfs(오른쪽)

오른쪽으로 내려가는거 depth별로 1개씩만 빼면 되는거 아닌가

12-2=10;

-1이나 0은 없는거임
*/