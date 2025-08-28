#include <string>
#include <vector>

using namespace std;

pair<int, int> nCnt; // 0, 1
pair<int, int> ansCnt; // 0, 1

int solution(int n) {
    int answer = n;

    int temp = n;
    while(temp > 1){
        if(temp%2 == 0) nCnt.first++;
        else nCnt.second++;

        temp/=2;
    }
    nCnt.second++;

    bool found = false;
    while(!found){
        answer++;
        ansCnt.first = 0;
        ansCnt.second = 0;

        temp = answer;
        while(temp > 1){
            if(temp%2 == 0) ansCnt.first++;
            else ansCnt.second++;

            temp/=2;
        }
        ansCnt.second++;

        if(nCnt.second == ansCnt.second) found = true;

    }

    return answer;
}