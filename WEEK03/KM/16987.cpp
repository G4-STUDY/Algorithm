#include <iostream>

using namespace std;
int n;
int arr[8][2]; //내구도,무게
int ans=0;

void calc(){
    int cnt=0;
    for(int i=0;i<n;i++){
        if(arr[i][0]<=0) cnt++;
    }
    ans=max(ans,cnt);
    return;
}

void dfs(int idx){
    if(idx>=n){//맨마지막 계란까지 다했으면
        calc();
        return;
    }
    if(arr[idx][0]<=0){//내계란이 깨져있으면
        dfs(idx+1);//다음계란을집어
        return;
    }
    bool flag=true;//계란깨기 한번이라도 했는지
    for(int i=0;i<n;i++)
    {
        if(idx==i||arr[i][0]<=0)continue;
        //계란깨기
        flag=false;
        arr[i][0]-=arr[idx][1];
        arr[idx][0]-=arr[i][1];
        dfs(idx+1);
        arr[i][0]+=arr[idx][1];
        arr[idx][0]+=arr[i][1];
    }
    if(flag){//나빼고 전부 깨진계란이면
        calc();
        return;
    }
}

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i][0]>>arr[i][1];
    }
    dfs(0);
    cout<<ans;
}