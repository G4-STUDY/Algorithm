#include <iostream>
#include <vector>

using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;

    vector<int> dq;
    dq.push_back(0);
    for(int station : stations){
        if(station - w < 1 && dq[dq.size()-2] != 1) dq.push_back(1);
        else if(dq[dq.size()-1] >= station - w) dq.pop_back();
        else dq.push_back(station-w);

        if(station + w > n) dq.push_back(n);
        else dq.push_back(station+w);
    }
    dq.push_back(n+1);

    int val = (2*w) + 1;
    for(int i=0; i<dq.size()-1; i+=2){
        int a = dq[i];
        int b = dq[i+1];

        //cout << a << " " << b << "\n";
        int cnt = b - a - 1;

        if(cnt % val == 0) answer += cnt / val;
        else answer += (cnt / val) + 1;
    }

    return answer;
}

/**
처음에 설치된데 제외 나머지 다 커버하려면 기지국 최소 몇개 더 필요한가
n이 2억개..

빈칸의 개수를 센다
빈칸/(2*w+1) 이게 딱 안나눠 떨어지면 + 1

배열...에 저장 안해도 될 것 같은데
이어지는 숫자 처음 끝만 저장해도?

station - w, station + w 만 저장
0 3 5 10 11 n+1

3 - 0 - 1; 2
10 - 5 - 1; 4

0 7 11 17

7-0-1 // 6
16 - 11

겹치는 경우를 고려못했다...


3,4,11에 설치되어 있으면?

0 1 1 1 1 0 0 0 0 1 1

0 2 5 10 11 12
근데 지금 로직으로는

0 2 4 3 5 10 11 12

앞에 자기 보다 큰게 있으면 둘다 지워버려?

*/