#include <iostream>
#include <vector>
#include <sstream>
#include <queue>

using namespace std;

int n;
int pre[10001];
int price[10001];
int startt[10001];
vector<int> edge[10001];

int main()
{
    string str,tmp;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>price[i];
        int m;
        cin>>m;
        for(int j=0;j<m;j++){
            pre[i]++;
            int x;
            cin>>x;
            edge[x].push_back(i);
        }
    }
    int answer=0;
    queue<pair<int,int>> q;
    for(int i=1;i<=n;i++){
        if(pre[i]==0)q.push({0,i});
    }
    while(!q.empty())
    {
        int curt=q.front().first;
        int cur=q.front().second;
        q.pop();
        int nextt=startt[cur]+price[cur];
        answer=max(answer,nextt);
        for(int next:edge[cur]){
            startt[next]=max(startt[next],nextt);
            if(--pre[next]==0){
                q.push({startt[next],next});
            }
        }
    }
    cout<<answer;

    return 0;
}