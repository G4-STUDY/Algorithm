#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<int> cores) {
    int answer = 0;

    priority_queue<vector<int>, vector<vector<int> >, greater<vector<int> > > pq;
    vector<int> v;

    //코어보다 작업이 더 적은 경우 처리
    if(n <= cores.size()){
        return n;
    }

    for(int i=0; i< cores.size(); i++){
        pq.push({cores[i], i}); //끝나는 시간, 코어 번호
    }

    for(int i=cores.size(); i<n; i++){
        vector<int> cur = pq.top();
        pq.pop();

        int time = cur[0];
        int num = cur[1];
        answer = num;

        pq.push({time+cores[num], num});
    }

    return answer+1;
}

/**
코어별로 작업 시간 다름
한 코어 끝나면 빈 코어가 작업 시작
앞코어부터 ㄱ

마지막 작업을 처리하는 코어의 번호

0시간 1 2 3
1시간 4
2시간 5 6
3시간


(작업, 코어, 끝나는 시간)
(1, 1, 1)
(2, 2, 2)
(3, 3, 3)
(4, 1, 2)
(5, 1, 3)
(6, 2, 4)

초기 코어 개수만큼 넣어
for(코어개수부터 n까지)
{
    pq.pop
    거기서 시간에 코어의 타임 더해서 다시 넣어
}


*/
