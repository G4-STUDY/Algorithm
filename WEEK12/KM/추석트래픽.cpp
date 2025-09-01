#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

vector<pair<int,int>> arr;

int htosss(int h){
    return h*3600000;
}
int mtosss(int m){
    return m*60000;
}

int stosss(int s){
    return s*1000;
}

bool cmp(pair<int,int> a,pair<int,int> b){
    if(a.first==b.first)
        return a.second<b.second;
    return a.first<b.first;
}

int solution(vector<string> lines) {
    int answer = 0;
    for(string s : lines){
        string hour=s.substr(11,2);
        string miniute=s.substr(14,2);
        string second=s.substr(17,2);
        string msecond=s.substr(20,3);
        string durings=s.substr(24,1);
        int time=stoi(durings)*1000;
        if(s[25]=='.'){
            time+=stoi(s.substr(26,s.size()-26));
        }
        int end=htosss(stoi(hour))+mtosss(stoi(miniute))+stosss(stoi(second))+stoi(msecond);
        int start=end-time;
        end+=998;//보정
        arr.push_back({start,end});
    }
    sort(arr.begin(),arr.end(),cmp);
    int cnt=0;
    priority_queue<int,
    vector<int>,
    greater<int>
    >pq;
    for(pair<int,int> p:arr){
        int st=p.first;
        int end=p.second;
        while(true)
        {
            if(pq.empty())break;
            int cur=pq.top();
            if(cur<st){
                pq.pop();
                cnt--;
            }
            else{
                break;
            }
        }
        pq.push(end);
        cnt++;
        answer=max(cnt,answer);
    }
    return answer;
}
/*
1초 1000
1분 60000
60*24*60000
1440*60000
86400000
끝나는시간에 1초더해서 하면되는거아닌가
998ms 더해야되네..

시작시간기준으로 정렬하고 우선순위큐에 끝나는시간 넣기
해당작업 시작시간보다 끝나는시간이 빠른거 빼고 넣기
pq size 갱신

*/