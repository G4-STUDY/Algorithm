#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

priority_queue<pair<int,pair<int,int>>,
vector<pair<int,pair<int,int>>>,
greater<pair<int,pair<int,int>>>
>pq;//{처리시간,{요청시간,넘버}}

vector<pair<int,pair<int,int>>> myjobs; //{요청시각,{처리시간,넘버}}


int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int num=0;//jobs.size()
    for(vector<int> job :jobs){
        myjobs.push_back({job[0],{job[1],num++}});
    }
    sort(myjobs.begin(),myjobs.end());
    int idx=0;
    int time=0;
    while(idx<num){//큐에 다넣을때까지
        //현재시간보다 요청시간이 작거나 같으면 다넣어
        while(idx<num&&myjobs[idx].first<=time){
            pq.push({ myjobs[idx].second.first, { myjobs[idx].first, myjobs[idx].second.second } });
            idx++;
        }
        //현재시간보다 요청시간이 작은게 없어? 그럼 요청시간이 더 뒤에있는거니까 idx에 있는거 넣어
        if(pq.empty()){
            time=myjobs[idx].first; //넣고 시간 조정
            pq.push({ myjobs[idx].second.first, { myjobs[idx].first, myjobs[idx].second.second } });
            idx++;
        }
        while(idx<num&&myjobs[idx].first<=time){//시간 바꼈으니까 또 넣어줘야지
            pq.push({ myjobs[idx].second.first, { myjobs[idx].first, myjobs[idx].second.second } });
            idx++;
        }
        if(idx==num)break;//큐에 이미 다넣었으면 더볼필요 없어
        //큐에 뭐가 있으면 일단 실행시켜야되니까 pop하고 time = end
        if(!pq.empty()){//이건 빼도 될거같긴한데..
            pair<int,pair<int,int>> qjob=pq.top();
            int runs=qjob.second.first;
            int runcost=qjob.first;
            int runidx=qjob.second.second;
            pq.pop();
            //cout<<runidx<<':'<<time<<','<<time+runcost<<'\n';
            time=time+runcost;//작업끝나는시간
            answer+=time-runs;//작업끝난시간 - 요청시간
        }
    }
    //미쳐 queue에 못들어간친구들 넣어주기
    while(idx<num){
        pq.push({ myjobs[idx].second.first, { myjobs[idx].first, myjobs[idx].second.second } });
        idx++;
    }
    //이제 큐에서 하나씩 빼면서 알아서 하세요 ㅎㅎ;
    while(!pq.empty()){
            pair<int,pair<int,int>> qjob=pq.top();
            int runs=qjob.second.first;
            int runcost=qjob.first;
            int runidx=qjob.second.second;
            pq.pop();
            //cout<<runidx<<':'<<time<<','<<time+runcost<<'\n';
            time=time+runcost;//작업끝나는시간
            answer+=time-runs;//작업끝난시간 - 요청시간
        }
    return answer/num;
}

/*
일단 요청 시각으로 정렬 ㄱㄱ

*/