#include <iostream>

using namespace std;

int n,m;
bool visit[9]; //방문처리
int arr[8]; //조합저장
void printarr(){//출력함수
    for(int i=0;i<m;i++){
        cout<<arr[i]<<' ';
    }
    cout<<'\n';
}

void comb(int cnt) 
{
    if(cnt==m){//m개만큼 뽑았으면
        printarr();//출력
        return;
    }
    for(int i=1;i<=n;i++){
        if(visit[i])continue;
        arr[cnt]=i; //조합 cnt번째에 i 넣기
        visit[i]=true; //방문처리
        comb(cnt+1);
        visit[i]=false; //방문처리풀기
    }
}

int main()
{
    cin>>n>>m;
    comb(0);
    return 0;
}