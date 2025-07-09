#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> dp;
int main()
{
    cin>>n;
    int t,p;
    dp.resize(n+2);
    for(int i=1;i<=n;i++){
        cin>>t>>p;
        dp[i]=max(dp[i-1],dp[i]);
        if(t+i<=n+1){
            dp[t+i]=max(dp[t+i],dp[i]+p);
        }
    }

    cout<<max(dp[n],dp[n+1]);
    return 0;
}