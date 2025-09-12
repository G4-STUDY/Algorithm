#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<vector<int>> jobs) {
    int total = 0;
    
    priority_queue<pair<int, pair<int, int>>,
                    vector<pair<int, pair<int, int>>>,
                    greater<pair<int, pair<int, int>>>> pq; // 요청시각 정렬 {요청시각, {소요시간, 번호}}
    
    priority_queue<pair<int, pair<int, int>>,
                    vector<pair<int, pair<int, int>>>,
                    greater<pair<int, pair<int, int>>>> waiting; // 소요시간 정렬 {소요시간, {요청시각, 번호}} 
    int num = 0;
    for(vector<int> v : jobs)
    {
        pair<int,pair<int, int>> job = {v[0], {v[1], num++}};
        pq.push(job);
    }
    
    int time = 0;
    
    while(!pq.empty() || !waiting.empty())
    {
        //현시점에서 대기큐 넣을거있는지 확인
        while(!pq.empty())
        {
            pair<int, pair<int, int>> temp = pq.top();
            if(temp.first <= time)
            {
                waiting.push({temp.second.first, {temp.first, temp.second.second}});
                pq.pop();
            }
            else break;
        }
        
        //대기큐에서 꺼내서 실행 
        if(waiting.empty()) time = time + 1;
        else
        {
            pair<int, pair<int, int>> cur = waiting.top(); waiting.pop();
            int finish_time = time + cur.first;
            int turnaround_time = finish_time - cur.second.first;
            total += turnaround_time;
            time = finish_time;
        }
    }
    return total / jobs.size();
}