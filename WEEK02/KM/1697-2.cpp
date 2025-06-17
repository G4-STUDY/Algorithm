#include <iostream>
#include <queue>
using namespace std;

bool visit[100001];

//너비탐색이유 최단시간찾는거니까 그이후는찾을필요 x

int main()
{
    int n,k;
    cin>>n>>k;
    queue<pair<int,int>> q;
    visit[n]=true;  //방문처리
    q.push({n,0});  
    while(!q.empty())
    {
        int cur = q.front().first;  //현재위치
        int num = q.front().second; //시간
        q.pop();
        if(cur==k){ //k만났으면 시간출력후 break or return
            cout<<num;
            break;
        }
        if(cur*2<100001){   //순간이동(*2) 범위체크
            if(!visit[cur*2]){  //방문안했으면
                visit[cur*2]=true;  
                q.push({cur*2,num+1});  //q에넣기
            }
        }
        if(0<=cur-1){   //범위체크 cur-1
            if(!visit[cur-1]){//방문체크
                visit[cur-1]=true;
                q.push({cur-1,num+1});  //방문
                
            }
        }
        if(cur+1<100001){//위와 동일 cur+1
            if(!visit[cur+1]){
                visit[cur+1]=true;
                q.push({cur+1,num+1});
                
            }
        }
    }
    return 0;
}