#include <iostream>

using namespace std;
#define MOD 1000000009;

int T,n,cnt;
long long dp[1000001];
int main()
{
    cin>>T;
    dp[1]=1;
    dp[2]=2;
    dp[3]=4;
    for(int i=4;i<1000001;i++){
        dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
        dp[i]%=MOD;
    }
    while(T--)
    {
        cin>>n;
        cout<<dp[n]<<'\n';
    }
    return 0;
}
