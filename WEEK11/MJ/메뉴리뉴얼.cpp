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
            Recul(orders[j], orders[j].size(), course[i], 0, 0); // 이 함수가 한번 실행되면 한명의 손님이 주문한 메뉴 조합에서
                                                                 // course[i]개만큼의 메뉴를 뽑은 모든 경우의 수를 map에 저장함
                                                        
        }
        // 루프가 끝나면 모든 조합의 주문 횟수가 map에 저장됨
        // course[i] 별로 가장 많이 주문한 횟수값이 max_cnt에 저장됨
        for (auto iter = m.begin(); iter != m.end(); ++iter) {
            // 메뉴 조합 별 주문 횟수가 max_cnt와 같을 경우, 그 조합을 answer 배열에 추가함
            if (max_cnt > 1 && iter->second == max_cnt && iter->first.size() == course[i]) answer.push_back(iter->first);
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}
