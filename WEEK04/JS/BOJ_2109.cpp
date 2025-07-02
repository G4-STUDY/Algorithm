#include<bits/stdc++.h>
using namespace std;

struct cmp
{
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        if(a.first != b.first) return a.first < b.first;
        else return  a.second < b.second;
    }
};

priority_queue < pair<int, int>, vector<pair<int, int>>, cmp> day_and_pay;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int max_pay_sum = 0;
    vector<int> used_day;
    
    int n;
    cin >> n;
    pair<int, int> tmp;
    set<int> days_set;
    for(int i = 0; i < n; i++)
    {
        cin >> tmp.second; //pay
        cin >> tmp.first; //day
        day_and_pay.push(tmp);
        days_set.insert(tmp.second);
    }
    
    for(int d : days_set)
    {
        used_day.push_back(d);
    }
    int day = used_day.back(); //20 
    while(1)
    {
        pair<int, int> cur = day_and_pay.top();
        day_and_pay.pop();
        if(cur.first >= day)
        {
            max_pay_sum += cur.first;
            day --; 
            day_and_pay.pop();
        }
        else
        {
            cur.first = used_day.back();
            day_and_pay.push(cur);
        }
    }


   
}

/*
강의 하루에 최대 한개
d=10 강의는 1~10일 모두 강연 가능 



d=2 -> 첫째날, 둘째날 
d=1 -> 첫째날
하루에 한개 
1,50
1,20
2,8
2,10
3,10
10,50
20,5
20,20

20,5    +5
10,50   +50
3,10    +20
2,100   +100

1,20    +20     
1,8
1,2

day=18 
20,10 
20,5  

10,50
3,10
2,100
2,8
1,20
1,2




*/