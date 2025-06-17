#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n,k;
int p[100001];  //어디서왔는지 기록 p[a]=b  a는 b에서 왔다
bool visit[100001]; 
int dx[2]={1,-1};
priority_queue<pair<int,int>,
vector<pair<int,int>>,
greater<pair<int,int>>
> pq;

int main()
{
    cin>>n>>k;
    for(int i=0;i<100001;i++)
    {
        p[i]=-1;    //방문안했으면 -1
    }
    p[n]=n;     //시작점은 부모 n처리
    visit[n]=true;  //방문처리
    pq.push({0,n});
    while (!pq.empty())
    {
        int cur=pq.top().second;
        int num=pq.top().first;
        pq.pop();
        if(cur==k){
            cout<<num<<"\n";    //도착했으면 시간출력
            break;
        }
        int next2=cur*2;    //두배순간이동
        if(next2<100001){
            if(!visit[next2]){
                p[next2]=cur;       //어디서왔는지
                visit[next2]=true;  //방문처리
                pq.push({num+1,next2});
            }
        }
        for(int i=0;i<2;i++)    //내려가거나 올라가거나
        {
            int next=cur+dx[i];
            if(0<=next&&next<100001)//범위체크
            {
                if(!visit[next]){
                    p[next]=cur;    //어디서왔는지
                    visit[next]=true;   //방문처리
                    pq.push({num+1,next});  //가자
                }
            }
        }
    }
    vector<int> ans;    //경로 출력용
    for(int i=k;p[i]!=i;){  //도착점부터 시작, 시작점은 p[i]==i 니까 시작점될때까지
        ans.push_back(i);
        i=p[i];//그전으로이동
    }
    ans.push_back(n);//시작점 넣기
    reverse(ans.begin(),ans.end()); //뒤집기
    for(int x:ans)
    {
        cout<<x<<' ';
    }
    return 0;
}