#include <iostream>

using namespace std;
int n;
int arr[100001];
int dp[100001];
int m;
int main()
{
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){
        dp[i]=100001;
    }
    dp[0]=arr[0];
    m=0;
    for(int i=1;i<n;i++){
        if(arr[i]>dp[m]){//증가하는경우
            dp[++m]=arr[i];
        }
        else{//작은경우
            int l=0;
            int r=m+1;
            while(l<r){
                int mid=(l+r)/2;
                if(dp[mid]<arr[i]){
                    l=mid+1;
                }
                else{
                    r=mid;
                }
            }
            dp[l]=arr[i];
        }
    }
    cout<<n-m-1;
    return 0;
}
