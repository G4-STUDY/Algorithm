#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> jobs) {
    int answer = 0;

    vector<vector<int>> newjobs;
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

    // 들어온 순서대로 정렬
    for(int i=0; i<jobs.size(); i++){
        vector<int> v;
        pq.push({jobs[i][0], jobs[i][1], i}); // 요청시간, 처리시간, 번호
    }

    while(!pq.empty()){
        newjobs.push_back(pq.top());
        pq.pop();
    }

    int time = 0;
    int idx = 0;

    while(true){
        if(idx >= newjobs.size()) break;

        while(idx < newjobs.size() && time >= newjobs[idx][0]){
            vector<int> v;
            v.push_back(newjobs[idx][1]); //처리시간
            v.push_back(newjobs[idx][0]); //요청시간
            v.push_back(newjobs[idx][2]); //번호
            pq.push(v);
            idx++;
        }

        if(pq.empty()) {
            time++;
            continue;
        }

        vector<int> cur = pq.top();
        pq.pop();

        time += cur[0];
        answer += time - cur[1];
        cout << time << " " << cur[1] << " \n";
    }

    while(!pq.empty()){
        vector<int> cur = pq.top();
        pq.pop();

        time += cur[0];
        answer += time - cur[1];
        cout << time << " " << cur[1] << " \n";
    }

    return answer / jobs.size();
}

/*
우선순위 : 시간 작음, 요청 빠름, 번호 작음
각 작업별로 끝시간 - 시작시간으로 반환시간 저장 후 평균 내야함

t가 가면서 넣기? 0초에서 시작
잡스를 돌면서 t와 잡스의 0번과 같냐?
그럼 pq에 넣어
그리고 빌때까지 꺼내서 돌려 -> 끝나는 시간 나오지
끝나는 시간과 잡스의 0번이 같을때까지 pq에 넣어?

t = 0
for(int i=0; i<jobs.size(); i++){
    while(t >= jobs[i][0] && i < jobs.size()){
        pq.push(잡 정보)
        i++ // i 인덱스 넘어감 유의
    }

    pq가 빌때까지 꺼내서 돌림
    - 팝
    - t += 처리시간
    - 답 += t - 요청시간
}

int t = 0;
int idx = 0;
while(idx < jobs.size()){
    while(t >= jobs[i][0]){
        pq.push(jobs([i])
        i++
    }

    if(pq.empty()) t++; continue;

    while(!pq.empty){
        pop
        t += 처리시간
        answer += t - 요청시간
    }
}

*/