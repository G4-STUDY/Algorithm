//백준 14501 퇴사 2 
#include<iostream>
#include<vector>
#define ll long long
using namespace std;

vector<int> en(2000000); //i일에 일했을 때 끝나는 날짜 
vector<int> pay(2000000); //i일에 일했을 때 받는 금액  
vector<ll> dp(2000000); //i일에 시작했을 때 받을 수 있는 최대 이익

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    int T,P; //걸리는 일 수, 이익 
    
    cin >> N;
    for(int i = 1; i <= N; i++)
    {
        
        cin >> T >> P;
        en[i] = i + T - 1;
        if(en[i] > N)
        {
            pay[i] = 0; 
        }
        else
        {
            pay[i] = P;
        }
    }
    dp[N] = pay[N];

    for(int i = N - 1; i >=1; i--)
    {
        //i일 포함된 case vs i일 포함안된 case
        dp[i] = max(dp[i+1], pay[i] + dp[en[i]+1]);
    }

    cout << dp[1];
    return 0;

    
}