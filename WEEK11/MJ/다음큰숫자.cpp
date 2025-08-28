#include <string>
#include <iostream>
#include <vector>

using namespace std;

int solution(int n) {
    
    int answer = 0;
    int one_cnt_n = 0;
    int one_cnt_nxt_n = 0;
    for (int u = 1; u <= 1000000; u *= 2) {
        if (n & u) one_cnt_n++; // n 의 1 개수 세기
    }
    for (int u = n + 1; u <= 1000000; u++) {
        one_cnt_nxt_n = 0;
        for (int v = 1; v <= 1000000; v *= 2) {
            if (u & v) one_cnt_nxt_n++; // n보다 큰 숫자들의 1 개수를 세다가
        }
        if (one_cnt_n == one_cnt_nxt_n) { // n과 1의 개수가 같은 숫자를 찾으면 루프 탈출
            answer = u;
            break;
        }
    }
    return answer;
}
