#include <iostream>
#include <queue>

using namespace std;
long long answer=0;
int edge[1001][1001];
bool visit[1001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int w;
            cin>>w;
            edge[i][j]=w;
        }
    }
    priority_queue<pair<int,int>,
    vector<pair<int,int>>,
    greater<pair<int,int>>
    >pq;
    //{cost,임의의 정점}
    pq.push({0,1});
    //방문수
    int cnt=0;
    while (cnt<n)//전부 방문하기 전까지
    {
        int cost=pq.top().first;
        int cur=pq.top().second;
        pq.pop();
        if(visit[cur])continue;
        //방문처리
        visit[cur]=true;
        cnt++;
        //정답갱신
        answer+=cost;
        for(int i=1;i<=n;i++){
            //이미방문 continue
            if(visit[i])continue;
            //{cost,next}
            pq.push({edge[cur][i],i});
        }
    }
    cout<<answer;
    return 0;
}

//prim으로 풀어보자