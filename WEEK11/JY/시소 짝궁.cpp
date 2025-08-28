#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(vector<int> weights) {
    long long answer = 0;
    long long cnt = 0;

    vector<double> dist = {1.0, 2.0, 3/double(2), 4/double(3) };

    sort(weights.begin(), weights.end());
    for(int i=0; i<weights.size()-1; i++){
        //cout << weights[i] << " ";
        for(int j=0; j<4; j++){
            cnt = upper_bound(weights.begin()+i+1, weights.end(), weights[i]*dist[j])
                - lower_bound(weights.begin()+i+1, weights.end(), weights[i]*dist[j]);
            //cout << cnt << " ";
            answer += cnt;
        }
        //cout << "\n";
    }
    return answer;
}


// long long solution(vector<int> weights) {
//     sort(weights.begin(), weights.end());
//     vector<int> cont({2, 3, 4});
//     long long answer = 0;
//     for(int i = 0; i < weights.size(); i++)
//         for(int j = i + 1; j < weights.size(); j++)
//         {
//             if(weights[i] == weights[j]) answer++;
//             else if(weights[i] * 4 == weights[j] * 3) answer++;
//             else if(weights[i] * 4 == weights[j] * 2) answer++;
//             else if(weights[i] * 3 == weights[j] * 2) answer++;
//         }
//     return answer;
// }