#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
map<string, int> m; // (코스 , 빈도)
map<int, int> mx; //(코스 길이, 최대 빈도)
string cur; 
void findCombination(int len, int st, int n, string order);

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    //특정 코스에 대한 빈도 테이블, 특정 길이에 대한 최대 빈도 테이블 만들기(findCombination)
    for(auto order : orders)
    {
        //주문 정렬
        sort(order.begin(), order.end());
        int n = order.size(); //손님 한명에 대해 주문한 단품 수
        //길이 2 ~ n 단품메뉴조합 확인 
        for(int len = 2; len <= n; len++)
        {
            cur.clear();
            findCombination(len, 0, 0, order); //길이 len 짜리 (2~n) 조합 모두 구하고 map에 갱신
        }
    }
    // p == (코스, 빈도)
    for(auto p : m)
    {
        //p == (코스, 빈도)
        if(p.second < 2) continue; // 1명에게만 주문된 코스는 pass
        for(int n : course)
        {
            if(p.first.size() != n) continue; //orders에 포함된 길이 아니면 pass
            if(p.second == mx[n]) answer.push_back(p.first); //길이 n 인 코스중 최대빈도면 포함 
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}
//                  목표 길이, 시작 인덱스, 현재 길이, order 
void findCombination(int len, int st ,int n, string order){
    //order로부터 길이 len 인 코스 완성 
    if(n == len){
        if(m.find(cur) == m.end())
        {
            m[cur] = 1; //코드 cur 빈도 1
            
        }
        else
        {
            m[cur] += 1; //코스 cur 에대해 빈도 증가
            
        }
        if(mx.find(len) == mx.end()) mx[len] = m[cur];
        //코드 cur 의 빈도가 길이 len 인 코스의 빈도들중 가장 크다면 갱신 
        if(mx[len] < m[cur])
        {
            mx[len] = m[cur];  
        }
    }
    
    for(int i = st; i < order.size(); i++){
        cur.push_back(order[i]);
        findCombination(len, i + 1, n + 1, order);
        cur.pop_back();
    }
}