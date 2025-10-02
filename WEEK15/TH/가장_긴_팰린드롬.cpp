#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int get_longgest_pel(string s, int mid)
{
    int idx = 1;
    int ret_odd = 1;
    
    while(true){
        // 인덱스가 범위 넘어가면 종료
        if((mid-idx) < 0) break; 
        if (s.size() < (mid+idx)) break;
        // 양 옆이 다르면 종료
        if(s[mid-idx] != s[mid+idx]) break;
        // 팰린드롬처리
        idx++;
        ret_odd += 2;
    }
    
    idx = 0;
    int ret_even = 0;
    int couple = mid + 1;
    
    while(true){
        // 인덱스가 범위 넘어가면 종료
        if((mid-idx) < 0) break; 
        if (s.size() < (couple+idx)) break;
        // 양 옆이 다르면 종료
        if(s[mid-idx] != s[couple+idx]) break;
        // 팰린드롬처리
        idx++;
        ret_even += 2;
    }
    
    
    return max(ret_odd, ret_even);
}

int solution(string s)
{
    int answer=0;

    int start = 0;
    int end = s.size()-1;
    
    for(int i=0; i<s.size(); i++){
        answer = max(answer, get_longgest_pel(s,i));
    }
    
    

    return answer;
}