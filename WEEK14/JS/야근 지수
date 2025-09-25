#include <string>
#include <vector>
#include <queue>
using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    priority_queue<int> pq; //최대힙
    
    for(int work : works)
    {
        pq.push(work);
    }
    
    while(n--)
    {
        int cur_work = pq.top(); pq.pop();
        cur_work--;
        if(cur_work < 0) cur_work = 0;
        pq.push(cur_work);
    }
    
    while(!pq.empty())
    {
        int cur_work = pq.top(); pq.pop();
        answer += (cur_work * cur_work);
    }
    
    
    
    return answer;
}

/*
야근 피로도: 야근 시작 시점에서 남은 일의 작업량 제곱의 합
n시간 동안 야근 피로도 최소화하도록 일
1시간동안 1 작업량을 처리 가능 
퇴근까지 남은 시간 n 각 일에 대한 작업량 works
works = 4, 3, 3
4시간 ( 4작업량 처리가능 )
4-2, 3-1, 3-1 로 작업하면 남은 작업량의 합은 2^2 + 2^2 + 2^2 = 12 로 최소가 됨
그냥 가장 큰 작업량을 처리하면 되는거아님???

*/
