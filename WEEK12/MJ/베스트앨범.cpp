#include <string>
#include <vector>
#include <map>
#include <queue>
#include <iostream>
using namespace std;

map <string, priority_queue <pair<int, int>>> m;
map <string, int> m1;
map <int, string> m2;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    for (int u = 0; u < genres.size(); u++) {
        m[genres[u]].push({plays[u], -u});
        m1[genres[u]] += plays[u];
    }
    for (auto e : m1) {
        m2[-e.second] = e.first;
    }
    
    for (auto e : m2) {
        int cnt = 0;
        while(!m[e.second].empty()) {
            cnt++;
            if (cnt >= 3) break;
            answer.push_back(-m[e.second].top().second);
            m[e.second].pop();
        }
    }
    return answer;
}
