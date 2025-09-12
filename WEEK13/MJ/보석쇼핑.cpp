#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

unordered_map <string, int> m1;
unordered_map <string, int> m2;

vector<int> solution(vector<string> gems) {
    gems.push_back("dummy");
    vector<int> answer;
    for (int u = 0; u < gems.size(); u++) m1[gems[u]]++;
    int gem_cnt = m1.size() - 1;
    int cur_cnt = 0;
    
    int st = 0;
    int ed = 0;
    int st_result = 0;
    int ed_result = 0;
    int min_len = 0x7fffffff;
    while(ed < gems.size()) {
        if (cur_cnt != gem_cnt) {
            if (m2[gems[ed]] == 0) cur_cnt++;
            m2[gems[ed++]]++;
        }
        else {
            if (m2[gems[st]] == 1) cur_cnt--;
            m2[gems[st++]]--;
            if (min_len > ed - st) {
                min_len = ed - st;
                st_result = st;
                ed_result = ed;
                //cout << st << ' ' << ed << '\n';
            }
        }
    }
    answer.push_back(st_result);
    answer.push_back(ed_result);
    return answer;
}
