#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

priority_queue <int> pq;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    while(!works.empty()) {
        pq.push(works.back());
        works.pop_back();
    }
    
    int temp = 0;
    for (int u = 0; u < n; u++) {
        if (pq.top() == 0) break;  // ㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋ
        temp = pq.top();
        pq.pop();
        temp--;
        pq.push(temp);
    }
    while(!pq.empty()) {
        answer += pq.top()*pq.top();
        pq.pop();
    }
    return answer;
}

