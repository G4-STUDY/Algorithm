#include <string>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

priority_queue<int> pq;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    for(int w:works){
        pq.push(w);
    }
    while(n--&&!pq.empty()){
        int cur=pq.top();pq.pop();
        if(cur!=1)
        pq.push(--cur);
    }
    while(!pq.empty()){
        answer+=pow(pq.top(),2);
        pq.pop();
    }
    return answer;
}
/*
큰거부터 줄여야겟네
근데 n이 100만이네
works는 2만
우선순위큐에 넣고 뽑으면 간당간당한가

되긴하는데 벡터로 정렬하고
앞에서부터 뒤에꺼랑 비교하면서 빼는게 더 빠를거같다
뒤에꺼랑 같아지면 두작업을 한번에 빼고 또 뒤에꺼랑 같아지면 세작업을...

l r
9 5 5 5 5 3 3 2 1 

한턴에
n-=(l+1)
*/