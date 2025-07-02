#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n;
pair<int,int> arr[200001];
priority_queue<int,
vector<int>,
greater<int>
> pq;
int mx;
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i].first>>arr[i].second;
    }
    sort(arr,arr+n);
    mx=0;
    for(int i=0;i<n;i++){
        while(!pq.empty()){
            int t=pq.top();
            if(t<=arr[i].first)
                pq.pop();
            else{
                break;
            }
        }
        pq.push(arr[i].second);
        mx=max(mx,(int)pq.size());
    }
    cout<<mx;
    return 0;
}