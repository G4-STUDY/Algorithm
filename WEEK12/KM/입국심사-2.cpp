#include <iostream>
#include <string>
#include <vector>

using namespace std;
long long solution(int n, vector<int> times) {
    long long answer = 0;
    long long r=1000000000000000000;//1e19 로 하면 왜안들어가지.. 1<<60도 안됨...
    long long l=0;
    while(l<r){
        long long mid=(l+r)/2;
        long long sum=0;
        for(int time:times){
            sum+=mid/time;
        }
        if(sum>=n)r=mid;
        else l=mid+1;
    }
    answer=l;
    return answer;
}
/*

10억명..?
10억시간..?
우선순위큐로 하나씩 뽑는다? 10억명을?
ㄴㄴ
심사관 10만명?
for 심사위원
합+=시간 / 심사위원처리시간
합= 그시간에 처리가능한 사람수
lower_bound ㄱㄱ
최대값은=10억*10억;
*/