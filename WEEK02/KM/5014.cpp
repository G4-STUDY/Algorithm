#include <iostream>
#include <queue>
using namespace std;

int visit[1000000]; //방문처리+이동횟수저장
int f,s,g;
int dx[2]={0};  //dx[0]=x x층만큼 올라감 dx[1]=x x층 만큼 내려감
queue<pair<int,int>> q;


int main()
{
    cin>>f>>s>>g>>dx[0]>>dx[1]; //입력받기
    for(int i=0;i<=f;i++){
        visit[i]=1e9;   //s층이 0이니까 최대값넣기
    }
    q.push({s,0});//q에 (s층)넣기
    while(!q.empty())
    {
        int cur=q.front().first;    //현재위치
        int num=q.front().second;   //이동횟수
        //cout<<cur<<','<<num<<'\n';
        q.pop();
        visit[cur]=num;
        for(int i=0;i<2;i++)
        {
            int next;
            if(i%2==0)          //올라가요
                next=cur+dx[i];
            else                //내려가요
                next=cur-dx[i];
            if(0<next&&next<=f){    //0층은 없음!
                if(visit[next]==1e9){//방문한적없으면
                    visit[next]=num+1;//방문,이동거리처리
                    q.push({next,num+1});
                }
            }
        }
    }
    if(visit[g]==1e9){//g층 방문못했으면 못감
        cout<<"use the stairs";
    }
    else{   //출력
        cout<<visit[g];
    }
    return 0;
}