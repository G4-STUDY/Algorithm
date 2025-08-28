#include <string>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long solution(vector<int> weights) {
    sort(weights.begin(), weights.end());
    long long answer = 0;
    int weight = 0;
    for (int u = 0; u < weights.size(); u++) {
        weight = weights[u];

        // 양쪽의 무게가 같을때 짝꿍이 몇쌍 있는지 세기
        answer += upper_bound(weights.begin() + u + 1, weights.end(), weight) - lower_bound(weights.begin() + u + 1, weights.end(), weight); 
        for (int v = 2; v <= 4; v++) {           //--------------------------------------------
            for (int w = 2; w <= 4; w++) {       // 양쪽의 무게가 다를 때 균형이 맞는
                if (v == w) continue;            // 짝꿍이 몇쌍 있는지 세기
                if (weight * v % w) continue;    //--------------------------------------------
                answer += upper_bound(weights.begin() + u + 1, weights.end(), weight*v/w) - lower_bound(weights.begin() + u + 1, weights.end(), weight*v/w);
            }
        }
    }
    return answer;
}
