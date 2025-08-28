#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(vector<int> weights) {
    sort(weights.begin(), weights.end());
    vector<int> cont({2, 3, 4});
    long long answer = 0;
    for(int i = 0; i < weights.size(); i++)
        for(int j = i + 1; j < weights.size(); j++)
        {
            if(weights[i] == weights[j]) answer++;
            else if(weights[i] * 4 == weights[j] * 3) answer++;
            else if(weights[i] * 4 == weights[j] * 2) answer++;
            else if(weights[i] * 3 == weights[j] * 2) answer++;
        }
    return answer;
}