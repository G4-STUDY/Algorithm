#include <string>
#include <vector>
#include <queue>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;

    priority_queue<int> pq;
    for(int work : works){
        pq.push(work);
    }

    while(n--){
        int cur = pq.top() - 1;
        pq.pop();
        pq.push(cur);
    }

    while(!pq.empty() && pq.top() > 0){
        int cur = pq.top();
        pq.pop();
        answer += cur*cur;
    }

    return answer;
}

// 12m 18s