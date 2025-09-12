#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer;

    //보석의 종류 cnt
    map<string, int> m;
    for(string gem : gems){
        m[gem]++;
    }
    int cnt = m.size();

    map<string, int> type;
    int start = 0;
    int end = 0;
    int minVal = 0;

    for(string gem : gems){

        end++;
        type[gem]++;

        if(type.size() == cnt){
            while(true){
                if(type[gems[start]] <= 1){
                    break;
                }
                type[gems[start]]--;
                start++;
            }
            if(minVal == 0 || minVal > end - (start + 1) + 1){
                minVal = end - (start + 1) + 1;
                answer.clear();
                answer.push_back(start+1);
                answer.push_back(end);
            }
        }

    }

    return answer;
}

/*
모든 보석을 포함하는 가장 짧은 구간의 시작과 끝
여러개면 짧은 것 반환

투포인터인데?

새로 포함하고자 하는 애가 start랑 같냐?
- 같지 않으면 포함시켜
- 같으면 start를 땡겨

보석 다 포함했다!
- 중복 검사하면서 start 최대한 밀어


gem 다 돌면서
1. gems[start]랑 지금 gem이랑 같은지 비교
    ㄴ 같으면 start+1
    ㄴ 다르면 start는 그대로
    ㄴ 공통 end + 1

2. map의 사이즈 비교, 보석 종류랑 수가 같다면
    ㄴ end는 끝남
    ㄴ START 땡기기 시작

3. START 땡기기
    ㄴ GEMS[START]개수가 1보다 크다 (초과) 개수 하나 빼고 START 땡겨
    ㄴ 근데 1보다 작거나 같다 하는 순간 그게 정답임

근데 다 돌긴해야겠다
*/