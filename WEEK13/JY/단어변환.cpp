#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int minCnt;

// 한글자만 다른지 확인하는 함수
int check(string a, string b){
    int diff = 0;
    for(int i=0; i<a.size(); i++){
        if(a[i] != b[i]) diff++;
    }
    return diff > 1 ? 0 : 1;
}

void func(string cur, int idx, int cnt, string target, vector<string> words){

    if(cnt >= minCnt) return;

    if(cur.compare(target) == 0){
        minCnt = min(minCnt, cnt);
        return;
    }

    for(int i=idx; i<words.size(); i++){
        if(check(cur, words[i]) == 0) continue;
        cout << cur << " " << words[i] << " "<< cnt << "\n";

        func(cur, i+1, cnt, target, words);
        func(words[i], i+1, cnt+1, target, words);
    }
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;

    bool found = false;
    vector<string> words2;
    for(string word : words){
        words2.push_back(word);
        if(word.compare(target) == 0){
            found = true;
        }
    }
    words2.push_back(target);

    if(!found) return answer;

    minCnt = words.size()+1;
    func(begin, 0, 0, target, words2);
    answer = minCnt;

    return answer;
}

/**
1. words에 target이 없으면 0으로 종료
2. words에 target이 있다?
    - begin에서 target가는 모든 경우의 수를 구해?
    - 고른다/안고른다 2가지의 50승  앙대
    - 그치만 가지를 친다면? 이미 많아지는순간 안가면 되잖아 흠...

3. 한글자만 다른지는 어떻게 판별?
    - 하나씩보면 n만큼 더 걸리는데,,,
    - 일단 하나씩 본다고 칠게

func(string cur, idx, cnt){
 if(cnt >= minCnt) return; //가지치기
 if(cur == target){
    minCnt = min(minCnt, cnt);
    return;
 };

 for(int i=idx; i<word.size(); i++){
    if(check(cur, words[i])) continue; //한글지 다른지 판별하는거
    func(cur, i+1, cnt); // 선택 안함
    func(words[i], i+1, cnt+1) // 선택 함
 }


}


*/