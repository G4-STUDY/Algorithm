#include <iostream>

using namespace std;

int arr[15];
int n,ans=0;

bool check(int x,int idx)
{
    for(int i=0;i<x;i++){
        if(arr[i]==idx)  //i번줄에서 이미 idx를 먹은경우
            return false;
        if(abs(x-i)==abs(idx-arr[i]))//대각선에 있는경우
            return false;
    }
    return true;
}

void dfs(int x){
    if(x==n){
        ans++;
        return;
    }
    {
        for(int i=0;i<n;i++){
            if(check(x,i))
            {
                arr[x]=i; //넣을수있으면 넣어
                dfs(x+1);
            }
        }
    }
}

int main()
{
    cin>>n;
    dfs(0);
    cout<<ans;
    return 0;
}