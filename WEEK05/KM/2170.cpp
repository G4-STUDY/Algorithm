#include <iostream>
#include <algorithm>
using namespace std;

pair<int,int> arr[1000001];

int main()
{
    //이거안쓰면 시간초과
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n,x,y;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>x>>y;
        arr[i].first=x;
        arr[i].second=y;
    }
    int ans=0;
    sort(arr,arr+n);
    int st=arr[0].first;int en=arr[0].second;
    for(int i=1;i<n;i++)
    {
        if(en<arr[i].first){//다음시작이 끝보다크면
            ans+=en-st;//선하나 더하기
            st=arr[i].first;
            en=arr[i].second;
        }
        else{//선 연장
            en=max(en,arr[i].second);
        }
    }
    ans+=en-st;
    cout<<ans;
    return 0;
}
/*
0 1 2 3 4 5 6 7
  1 1 1 1   1 

1 3 st=1 en=3
2 5 st=1 en=5
3 5 st=1 en=5
    ans+=en-st;
6 7 st=6 en=7
    ans+=en-st;
*/