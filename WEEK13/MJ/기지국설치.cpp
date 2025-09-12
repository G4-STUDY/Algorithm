#include <iostream>
#include <vector>
#include <queue>
using namespace std;

queue <pair<int, int>> q;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    int range = 2*w + 1;
    int st = 0;
    int ed = 0;
    for (int u = 0; u < stations.size(); u++) {
        int st = stations[u] - w;
        int ed = stations[u] + w;
        if (st < 1) st = 1;
        if (ed > n) ed = n;
        q.push({ st, ed });
    }
    st = q.front().first;
    ed = q.front().second;
    q.pop();
    answer += (st - 1) / range;
    if ((st - 1) % range) answer++;
    while(!q.empty()) {
        if ((q.front().first - ed) > 1) {
            answer += (q.front().first - ed - 1) / range;
            if ((q.front().first - ed - 1) % range) answer++;
        }
        ed = q.front().second;
        q.pop();
    }
    answer += (n - ed) / range;
    if ((n - ed) % range) answer++;
    return answer;
}
