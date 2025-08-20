#include <iostream>
#include <queue>

using namespace std;
int n,w,l;
int truck[1001];
queue<pair<int,int>> q;//idx,time


int main()
{
    cin>>n>>w>>l;
    for(int i=0;i<n;i++){
        cin>>truck[i];
    }
    int weight=0;
    int ans=0;
    int time=0;
    for(int i=0;i<n;i++){
        while (!q.empty()&&q.front().second+w<time)
        {   //이미 다리에서 나간 트럭들 빼기
            int curw=truck[q.front().first];
            weight-=curw;
            q.pop();
        }
        if(q.size()>=w||weight+truck[i]>l){//다리에 자리가 없어요
            while(!q.empty()&& (q.size()>=w||weight+truck[i]>l)){
                int curt=q.front().second;
                int curw=truck[q.front().first];
                q.pop();
                //시간변경
                //weight변경
                time=curt+w;
                weight-=curw;
            }
        }
        q.push({i,time});//트럭 {idx,입장시간}
        weight+=truck[i];//트럭무게
        time++;//시간 1초증가
    }
    cout<<time+w<<'\n';//마지막트럭 입장시간+1+w
    return 0;
}