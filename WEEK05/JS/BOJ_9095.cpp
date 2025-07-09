//백준 9095 1, 2, 3 더하기
#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    int n;
    cin >> T;
    while(T--)
    {
        cin >> n;
        vector<int> dp(n+1); //인덱스 1 부터 
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 4;
        for(int i = 4; i <= n; i++)
        {
            dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
        }

        cout << dp[n] << '\n';
    }
    return 0;

}