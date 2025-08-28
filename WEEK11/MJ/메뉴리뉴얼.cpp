#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;
map <string, int> m;
char arr[11];
int vis[11];
int max_cnt;

void Recul(string s, int len, int pick, int cnt, char prev) {
    if (cnt == pick) {
        string temp;
        for (int u = 0; u < pick; u++) {
            temp += arr[u];
        }
        m[temp]++;
        if (m[temp] > max_cnt) max_cnt = m[temp];
        return;
    }
    
    for (int u = 1; u <= len; u++) {
        if (vis[u] == 1 || s[u - 1] <= prev) continue;
        vis[u] = 1;
        arr[cnt] = s[u - 1];
        Recul(s, len, pick, cnt + 1, s[u - 1]);
        vis[u] = 0;
    }
    
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    for (int i = 0; i < course.size(); i++) {
        max_cnt = 0;
        for (int j = 0; j < orders.size(); j++) {
            Recul(orders[j], orders[j].size(), course[i], 0, 0);
        }
        cout << max_cnt;
        for (auto iter = m.begin(); iter != m.end(); ++iter) {
            if (max_cnt > 1 && iter->second == max_cnt && iter->first.size() == course[i]) answer.push_back(iter->first);
            //cout << "key : " << iter->first << " value : " << iter->second << '\n';
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}
