#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
#include <iostream>

using namespace std;

unordered_map <string, int> m;
priority_queue <int> pq;

int vis[10];
int result[10];

bool Match(string a, string b) {
    if (a.length() != b.length()) return false;
    for (int i = 0; i < a.length(); i++) {
        if (a[i] != b[i] && b[i] != '*') return false;
    }
    return true;
}

void Pick(vector<string> a, vector<string> b, int cnt) {
    if (cnt == a.size()) {
        string s;
        for (int j = 0; j < a.size(); j++) {
            pq.push(result[j]);
        }
        for (int j = 0; j < a.size(); j++) {
            s += (pq.top()+48);
            pq.pop();
        }
        m[s]++;
        // cout << s;
        // cout << '\n';
        return;
    }
    for (int k = 0; k < b.size(); k++) {
        if (!Match(b[k], a[cnt])) continue;
        if (vis[k]) continue;
        vis[k] = 1;
        result[cnt] = k;
        Pick(a, b, cnt + 1);
        vis[k] = 0;
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;

    Pick(banned_id, user_id, 0);
    answer = m.size();
    return answer;
}
