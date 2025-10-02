#include <iostream>
#include <string>


using namespace std;
int solution(string s)
{
    int answer=1;
    int n = s.length(); // 문자열 길이
    int cnt = 0;        // 팰린드롬 길이 변수
    
    //------------------------------------
    // 홀수 길이 팰린드롬 찾기
    for (int u = 1; u < n; u++) {
        cnt = 1;
        for (int v = 1; v < n; v++) {
            if ((u-v) < 0 || (u+v) >= n) break; // 문자열 범위 밖으로 나가면 break
            if (s[u-v] != s[u+v]) break;        // 팰린드롬이 아니면 break
            cnt += 2;
        }
        if (answer < cnt) answer = cnt;
    }
    //------------------------------------
    
    //------------------------------------
    // 짝수 길이 팰린드롬 찾기
    for (int u = 0; u < n; u++) {
        cnt = 0;
        for (int v = 0; v < n; v++) {
            if ((u-v) < 0 || (u+v+1) >= n) break;
            if (s[u-v] != s[u+v+1]) break;
            cnt += 2;
        }
        if (answer < cnt) answer = cnt;
    }
    //------------------------------------

    return answer;
}
