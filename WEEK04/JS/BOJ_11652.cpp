#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool cmp(pair<ll, int> a, pair<ll, int> b)
{
    //개수의 내림차순으로 정렬, 개수 같다면 값 오름차순 정렬
    if(a.second != b.second) return a.second > b.second;
    else return a.first <b.first;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<ll> cards_val; // N개의 입력 카드 저장
    int N;
    cin >> N;
    for(int i = 0; i < N; i++)
    {    ll input_card;
        cin >> input_card;
        cards_val.push_back(input_card);
    }
    // cards_val 벡터 오름차순 정렬
    sort(cards_val.begin(), cards_val.end());
    
    // 가장 많은 카드 찾기
    vector<pair<ll, int>> val_num; // 값과 개수 쌍 저장

    ll prev = 0x7FFFFFFFFFFFFFFF;
    for (int i = 0; i < N; i++)
    {
        if (cards_val[i] == prev) continue;
            
        
        // 카드의 값
        ll val = cards_val[i];
        // 카드의 개수
        auto upper_it = upper_bound(cards_val.begin(), cards_val.end(), val);
        auto lower_it = lower_bound(cards_val.begin(), cards_val.end(), val);
        int num = upper_it - lower_it;

        val_num.push_back({val, num});
        prev = val; // 중복 방지
    }
    sort(val_num.begin(), val_num.end(), cmp);
    //정렬된 val_num 벡터의 첫번째값 출력 
    cout << val_num[0].first;
    return 0;
   
}

/*
1,1,1,2,2,2,3,3,3,3,4,4
*/