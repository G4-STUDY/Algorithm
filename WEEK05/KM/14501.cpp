#include <iostream>

using namespace std;

int n;
int dp[17];
int main()
{
    cin>>n;
    int t,p;
    for(int i=1;i<=n;i++){
        cin>>t>>p;//기간,돈
        dp[i]=max(dp[i-1],dp[i]);//전날까지가 더큰경우가 있나?
        if(t+i<=n+1){   //기간안에 상담완료할수 있어?
            dp[t+i]=max(dp[t+i],dp[i]+p);//이거하는게 더크면 갱신
        }
    }
    cout<<max(dp[n],dp[n+1]);//마지막
    return 0;
}
/*
7
dp[0]=0;
1=3 10
dp[1]=0;
dp[4]=10;
2=5 20
dp[2]=0;
dp[7]=20;
3=1 10
dp[3]=0;


*/