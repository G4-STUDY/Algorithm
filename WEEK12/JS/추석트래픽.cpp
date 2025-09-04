//오답 -> 20개/22개  

#include <string>
#include <vector>

using namespace std;

int solution(vector<string> lines) {
    int answer = 0;
    int n = lines.size();
    vector<pair<int, int>> line_points;
    vector<int> look_points;
    for(int i = 0; i < n; i++)
    {
        //ms 단위 변환 
        int st, en, t;
        string hh = lines[i].substr(11, 2);
        string mm = lines[i].substr(14, 2);
        string ss = lines[i].substr(17, 2);
        string sss = lines[i].substr(20, 3);
        string t_ss = lines[i].substr(24, 1);
        string t_sss;
        if(lines[i][25] == 's') t_sss = "0"; 
        else t_sss = lines[i].substr(26, lines[i].size() - 26);
        
        en = stoi(hh) * 3600000 + stoi(mm) * 60000 + stoi(ss) * 1000 + stoi(sss);
        t = stoi(t_ss) * 1000 + stoi(t_sss);
        st = en - t + 1;
        line_points.push_back({st, en});

        look_points.push_back(st);
        look_points.push_back(en);
    }
    
    for(int p : look_points)
    {
        int cur = 0;
        //현재 보는 1초 단위 구간
        int look_st = p;
        int look_en = p + 999; 
        //모든 구간 확인
        for(pair<int, int> line_point : line_points)
        {
            int line_st = line_point.first;
            int line_en = line_point.second;
            if(line_st > look_en || line_en < look_st) continue;
            cur++;
        }
        answer = max(answer, cur);
        
        
    }
    
    return answer;
}