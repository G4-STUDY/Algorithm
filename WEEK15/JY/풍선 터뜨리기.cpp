#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

map<int, int> vis;
priority_queue<int, vector<int>, greater<int> > pq;

int solution(vector<int> a) {
    int answer = 0;
    
    for(int num : a){
        pq.push(num);
    }
    int frontMin = 1000000001;
    int backMin = pq.top();
    pq.pop();
    
    for(int num : a){
        if(num == a[a.size()-1]) backMin = 1000000001;
        
        vis[num]++;
        if(num == backMin){
            while(vis[pq.top()] != 0){
                pq.pop();
            }
            backMin = pq.top();
        }
        
        if(num > frontMin && num > backMin) {
            answer++;
        }
        
        frontMin = min(frontMin, num);
    }
    
    return a.size()-answer;
}

/**
- 딱 한번만 작은걸 고를 수 있음
- 인접한것만 터뜨릴 수 있음

- 큰 것만 터뜨릴 수 있음 = 최솟값은 항상 남아
- 딱 한 번만 작은 것을 터뜨릴 수 있음
= 자신의 앞의 최솟값 & 자신의 뒤의 최솟값 중에 하나보다는 커야함
    둘 다 나보다 작으면 불가능
    
- 슬라이딩 윈도우 양쪽으로 두개?? 이게 맞나
- frontMin / backMin / idx
frontMin = 10억, backMin = 배열의 min값

frontMin은 들어오는 수랑 기존 min만 비교하면 되는데
backMin은 나가야하잖아...
pq에 넣어놓고 꺼냈는데 이미 방문했다 그러면 계

56m
*/
