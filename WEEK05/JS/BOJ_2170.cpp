//백준 2170 선긋기
#include<iostream>
#include<queue>
#define ll long long
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    //최소힙
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    int N;
    ll result = 0;
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        pair<ll, ll> input;
        cin >> input.first >>input.second;
        pq.push(input);
    }

    pair<ll, ll> cur =pq.top(); pq.pop();
    //엣지 케이스 예외 처리 (N == 1)
    if(pq.empty())
    {
        result += (cur.second - cur.first);
    }
    // N >= 2
    while(!pq.empty())
    {
        pair<ll, ll> nxt = pq.top(); pq.pop();
        //1.중첩되게 선 그은 경우
        if(nxt.first <= cur.second)
        {
            nxt.first = cur.first;
            nxt.second = max(cur.second, nxt.second);
            cur = nxt;
           
        }
        //2.중첩되지 않은 선 그은 경우
        //현재까지의 선 길이에 포함후 새로운 중첩 시작 
        else
        {
            result += (cur.second - cur.first);
            cur = nxt;
        }
        //현재 그은 선이 마지막 선인 경우 현재 길이 반영 
        if(pq.empty())
        {
             result += (cur.second - cur.first);   
        }
    }
    cout << result;
    return 0;
}