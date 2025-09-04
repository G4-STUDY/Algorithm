#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <limits.h>

using namespace std;

int check(int n, vector<int> times, long long t){
    long long sum = 0;
    for(int time : times){
        sum += t / time;
    }

    if(sum >= n) return 1;
    else return -1;
}

long long solution(int n, vector<int> times) {
    long long answer = 0;

    int maxTime = *max_element(times.begin(), times.end());

    long long low = 0;
    long long high = (long long)maxTime * n;

    while(low <= high){
        long long mid = (low+high) / 2;

        if(check(n, times, mid) == 1){
            answer = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }

    }

    return answer;
}


/**
이분탐색으로 시간 범위 줄여 나가기
그 시간안에 n명이 들어올 수 있는가?
들어올 수 있으면 줄이고
못들어오면 늘리고? 그리고 가장 마지막에 살아남은애가 될 것 같은데

n명 들어올 수 있는가?는 시간을 t로 가정
t를 times의 각 원소로 나눈 나머지의 합이
n보다 크면 시간 줄일 수 있음
n보다 작으면 시간 늘ㄹ여함
같으면 정답인가
*/