#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

#define En first
#define St second

priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
priority_queue <vector<int>, vector<vector<int>>, greater<vector<int>>> job_q;

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int start_time = 0;
    int end_time = 0;
    int processed = 0;
    bool harddisk_running = false;
    for (int u = 0; u < jobs.size(); u++) job_q.push(jobs[u]);
    for (int u = 0; u < 500005; u++) {
        while(!job_q.empty() && job_q.top()[0] == u) {
            pq.push({ job_q.top()[1], job_q.top()[0] });
            job_q.pop();
        }
        
        if (u == end_time) harddisk_running = false;
        if (harddisk_running || pq.empty()) continue;
        
        end_time = u + pq.top().En;
        start_time = pq.top().St;
        answer += (end_time - start_time);
        //cout << pq.top().En << ' '<< u << ' ' << pq.top().St << '\n';
        processed++;
        harddisk_running = true;
        if (processed == jobs.size()) break;
        pq.pop();
    }
    answer /= jobs.size();
    return answer;
}
