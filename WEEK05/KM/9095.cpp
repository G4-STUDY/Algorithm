#include <iostream>

using namespace std;

int T,n,cnt;
int dp[12];
int main()
{
    cin>>T;
    dp[1]=1;
    dp[2]=2;
    dp[3]=4;
    for(int i=4;i<11;i++){
        dp[i]=dp[i-1]+dp[i-2]+dp[i-3];//dp[i]=나타내는 방법수 i-1 ,i-2,i-3은 1,2,3 넣기
    }
    while(T--)
    {
        cin>>n;
        cout<<dp[n]<<'\n';
    }
    return 0;
}

    /*
    1
    11 2
    12 111 21  3
    13 112 22 121 1111 211 31
    */