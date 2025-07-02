#include <iostream>
#include <algorithm>
using namespace std;
int t,n;
pair<int,int> arr[100001];

bool cmp(pair<int,int> a,pair<int,int> b)
{
    if(a.first==b.first)
    {
        return a.second<b.second;
    }
    return a.first<b.first;
}
/*
nlogn
longist increase? x
점수x 등수임
*/
int main()
{
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>arr[i].first>>arr[i].second;
        }
        sort(arr,arr+n,cmp);
        int cnt=1;
        int tmp=arr[0].second;
        for(int i=1;i<n;i++){
            if(arr[i].second<tmp){
                cnt++;
                tmp=arr[i].second;
            }
        }
        cout<<cnt<<'\n';
    }
    return 0;
}