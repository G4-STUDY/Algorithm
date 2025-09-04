#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <iostream>

using namespace std;

map<string, double> m;
priority_queue<pair<double, string> > pq;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;

    for(int i=0; i<genres.size(); i++){
        m[genres[i]] += plays[i];
    }

    for(pair<string, double> temp : m){
        pq.push({temp.second, temp.first});
    }

    while(!pq.empty()){
        string cur = pq.top().second;
        cout << cur << "\n";
        pq.pop();

        priority_queue<pair<int, int> > play;

        for(int i=0; i<genres.size(); i++){
            if(cur.compare(genres[i]) == 0){
                play.push({plays[i], -i});
            }
        }

        int cnt = 0;
        while(!play.empty()){
            if(cnt == 2) break;
            answer.push_back(-play.top().second);
            play.pop();
            cnt++;
        }
    }

    return answer;
}

/**
장르별로 2곡
1. 장르 전체 플레이 수 많은 순서
2. 장르 내에서 플레이 많은 순서

--
1. 장르별 플레이 수를 구한다
    - 맵에 저장?
    - PQ로 옮겨?
2. 장르 내에서 플레이 수 구한다 (플레이수, 인덱스) 형태로 저장

*/