#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

vector<char> menu;
vector<char> hubo;
map<string, int> m[11];

bool cmp(pair<string, int>& a,
         pair<string, int>& b)
{
    return a.second > b.second;
}

void func(int num, int idx){
    if(hubo.size() == num){
        string s;
        for(char c : hubo){
            s += c;
        }

        m[num][s]++;
        return;
    }

    for(int i=idx; i<menu.size(); i++){
        hubo.push_back(menu[i]);
        func(num, i+1);
        hubo.pop_back();
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;

    for(string order : orders){
        menu.clear();
        for(char c : order){
            menu.push_back(c);
        }
        sort(menu.begin(), menu.end());

        for(int num : course){
            func(num, 0);
        }
    }

    for(int num : course){
        vector<pair<string, int> > v(m[num].begin(), m[num].end());
        sort(v.begin(), v.end(), cmp);

        if(v.empty() || v[0].second < 2) continue;

        int maxVal = v[0].second;
        int idx = 0;

        while(maxVal == v[idx].second){
            answer.push_back(v[idx].first);
            idx++;
        }

    }

    sort(answer.begin(), answer.end());
    return answer;
}