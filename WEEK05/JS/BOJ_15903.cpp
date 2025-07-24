//백준 15903 카드 합체 놀이
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    //최소힙
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    int n;
    int m;
    ll score = 0; 
    cin >> n >> m; // n >= 2 , m >= 0
    for(int i = 0; i < n; i++)
    {
        ll card_num;
        cin >> card_num;
        pq.push(card_num);
    }
    while(m--)
    {
        ll card1 = pq.top(); pq.pop();
        ll card2 = pq.top(); pq.pop();
        ll sum = card1 + card2;
        pq.push(sum);
        pq.push(sum);
    }
    //점수 출력 
    while(!pq.empty())
    {
        score += pq.top(); pq.pop();
    }
    cout << score;

    return 0;
}