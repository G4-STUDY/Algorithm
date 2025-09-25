#include <string>
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>

using namespace std;

set<string> list;
int global_answer = 0;

bool compare(string a, string b){
    if(a.length() != b.length()) return false;

    for(int i=0; i<a.length(); i++){
        if(a[i] == '*') continue;
        if(a[i] != b[i]) return false;
    }

    return true;
}

void func(vector<string> user_id, vector<string> banned_id, int idx, int flag){
    if(list.size() == banned_id.size()){
        for(string name : list){
            cout << name << " ";
        }
        cout << "\n";
        global_answer++;
        return;
    }

    string cur = banned_id[idx];
    for(int i=flag; i<user_id.size(); i++){
        // 조건에 맞고 포함 안시켰으면
        if(compare(cur, user_id[i]) && list.find(user_id[i]) == list.end()){
            list.insert(user_id[i]);
            func(user_id, banned_id, idx+1, flag+1);
            list.erase(list.find(user_id[i]));
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;

    func(user_id, banned_id, 0, 0);

    return global_answer;
}

/**
마스킹 주어질때 가능한 경우의 수

1번 겹치는거 없음 2개
2번 겹치는거 없음 2개 ->
3,4번 겹침 2개 두갠데 두칸? -> 1

걍 밴 아이디돌면서 가능한 리스트 만들고 거기서 완탐 돌리는것밖에 없나??

문자열 처리만 잘하면 뺑이 돌려도 가능할 것 같기도.. 8의 8제곱?

*/