#include <iostream>
#include <queue>
using namespace std;

int n,k;
int dp[100001];//방문처리!!
bool visit[100001]; //q에 넣었는지!!
priority_queue< pair<int,int> ,
vector<pair<int,int>> ,
greater<pair<int,int>>> q;  //우선순위큐 {time,location}
int main()
{
    cin>>n>>k;
    for(int i=0;i<100001;i++){
        dp[i]=-1;   //방문안햇으면 거리 -1로
    }
    q.push({0,n});
    while (!q.empty())
    {
        int num=q.top().first;  //시간
        int cur=q.top().second; //장소
        q.pop();
        if(cur==k){//도착했으면
            cout<<num;  //출력해
            break;
        }
        if(dp[cur]!=-1&&dp[cur]<=num) continue; //방문한적있는데 지금시간보다 빨리방문했으면 넘겨 
        dp[cur]=num;
        int next=cur*2; //cur의시간==cur*2의시간==cur*(2의n제곱)의시간
        while(next<100001&&next!=0){//0일땐 *2하면 안됌,범위체크
            if(visit[next]) break;  //이미 방문했으면 뒤에도 *2했겠지
            visit[next]=true;   //방문처리
            q.push({num,next}); //q에넣기
            next*=2;    //next에서 순간이동:next-next로
        }
        if(cur+1<100001)//1층올라가기
            q.push({num+1,cur+1});
        if(cur-1>=0)//1층 내려가기
            q.push({num+1,cur-1});
    }
    
    return 0;
}