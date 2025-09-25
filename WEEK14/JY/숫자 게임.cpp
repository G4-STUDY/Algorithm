#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;

    priority_queue<int> pq;
    for(int num:B){
        pq.push(num);
    }

    sort(A.begin(), A.end(), greater<>());
    for(int num:A){
        if(num < pq.top()){
            pq.pop();
            answer++;
        }
    }

    return answer;
}

/**
최대 승점을 리턴 = 최대한 많이 이겨야함 (비기기 x)

7 5 3 1
8 6 2 2

7 6 5 4
8 5 4 3

1. 큰 순서대로 정렬
2. 자신보다 큰 수가 있는가? 있으면 걔 빼고 정답+1
3. 없으면 지나감

이것도 그냥 피큐로?
탑에서 꺼내서 비교했는데 크다 그럼 빼고 진행 ㄱㄱ
탑에서 꺼내서 비교했는데 안크네? 그럼 다시 넣어 이런 느낌?

*/