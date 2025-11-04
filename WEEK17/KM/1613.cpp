#include <iostream>

using namespace std;

int n,m;
bool edge[401][401];
int s; 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        edge[a][b]=true;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                if(edge[j][i]&&edge[i][k])
                    edge[j][k]=true;
            }
        }
    }
    cin>>s;
    for(int i=0;i<s;i++){
        int a,b;
        cin>>a>>b;
        if(edge[a][b]){
            cout<<-1<<'\n';
        }
        else if(edge[b][a]){
            cout<<1<<'\n';
        }
        else{
            cout<<0<<'\n';
        }
    }
    return 0;
}