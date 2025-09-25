#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    
    priority_queue<int> pq;
    for(int i : works) pq.push(i);
    
    while(n-- && !pq.empty()){ // (1000000)
        int cur = pq.top();
        pq.pop();
        cur -= 1;
        if(cur <= 0) continue;
        pq.push(cur);
    }
    
    while(!pq.empty()){
        int cur = pq.top();
        pq.pop();
        answer += (cur*cur);
    }
    
    return answer;
}