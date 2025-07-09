//백준 11501 주식
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#define ll long long
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T;
    cin >> T;
    while(T--)
    {
        ll N; // 2 <= N <=1000000
        ll cur_max; //현재일 기준 최대값 
        ll result = 0;
        vector<ll> prices;
        cin >> N;
        for(int i = 0; i < N; i++)
        {
            ll price;
            cin >> price;
            prices.push_back(price);
        }
        //마지막 날부터 시작 
        cur_max = prices[N-1];
        for(int i = N-1; i >= 0; i--)
        {
            if(prices[i] < cur_max)
            {
                result += (cur_max - prices[i]);
            }
            //prices[i] >= cur_max
            else
            {
                cur_max = prices[i];
            }
        }
        cout << result << '\n';
    }
}

/*
앞에서부터가면서 
현재 전체 최대값 만나기 전까지 구매 
전체 최대값 만나는 날 구매한거 다팔기 
이후 남은것중 최대값 갱신 
다시 반복    
=> 시간 초과 

prices:1 1 3 1 2

tmp:2 1 3 1 1
pq:1 1 1 2 3


1 2 10 20 30 1 2 8  
*/