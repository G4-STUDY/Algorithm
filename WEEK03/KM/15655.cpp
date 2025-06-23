#include <iostream>
#include <algorithm>
using namespace std;

int n,m;
int ans[8];
int arr[8];
bool visit[8];

void comb(int x,int idx){ // 오름차순 조합뽑기
    if(x==m){
        for(int i=0;i<m;i++){
            cout<<ans[i]<<' ';
        }
        cout<<'\n';
        return;
    }
    for(int i=idx;i<n;i++){ //시작 idx부터
        if(visit[i])continue;
        visit[i]=true;
        ans[x]=arr[i];
        comb(x+1,i+1); //i+1부터 다음꺼 시작
        visit[i]=false;
    }
}

int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n); //정렬
    comb(0,0);
    return 0;
}