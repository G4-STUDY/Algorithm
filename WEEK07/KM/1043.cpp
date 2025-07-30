#include <iostream>
#include <vector>

using namespace std;

int n,m;
int num;
vector<int> know;
vector<int> party[51];
vector<int> edge[51];
bool check[51][51];
bool visit[51];


void dfs(int cur){
    for(int next:edge[cur]){
        if(visit[next])continue;
        visit[next]=true;
        dfs(next);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int x,tmp,ans=0;    
    cin>>n>>m;
    cin>>num;
    for(int i=0;i<num;i++)
    {
        cin>>x;
        //진실을 아는 사람
        know.push_back(x);
    }
    for(int i=0;i<m;i++){
        cin>>x;
        for(int j=0;j<x;j++){
            cin>>tmp;
            party[i].push_back(tmp);
        }
        for(int j=0;j<x;j++){
            for(int k=0;k<x;k++){
                if(k==j)continue;
                int node=party[i][k];
                int node2=party[i][j];
                //중복엣지 제거
                if(check[node][node2])continue;
                check[node][node2]=true;
                //엣지추가
                edge[node].push_back(node2);
            }
        }
    }
    for(int cur:know){//아는사람들에서 탐색
        if(visit[cur])continue;
        visit[cur]=true;
        dfs(cur);
    }
    /*
    */
    for(int i=0;i<m;i++){//파티마다
        bool flag=true;
        for(int who:party[i]){// visit 하나라도 true면 안됌
            if(visit[who]){
                flag=false;
                break;
            }
        }
        if(flag){ans++;}
    }
    cout<<ans;
    return 0;
}

/*

*/