#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int,int>> route;

int solution(vector<vector<int>> routes) {
    int answer = 0;
    for(vector<int> v:routes){
        route.push_back({v[1],v[0]});//끝점,시작점
    }
    sort(route.begin(),route.end());
    int idx=-30001;
    for(pair<int,int> p:route){
        if(idx<p.second){
            answer++;
            idx=p.first;
        }
    }
    return answer;
}

/*
일단 시작점 기준으로 정렬하고
제일끝 지점에 하나설치 
그다음꺼가 설치지점보다 멀면 하나더 추가..
[[-20, -15], [-19, -18], [-15, -5]] 이경우 틀림
끝점 기준으로 정렬하고
끝점에 설치하고 다음꺼 시작지점이 이 끝점보다 가까운지 체크
//끝점기준으로 정렬했으니까 시작지점만 체크하면 커버됌

*/