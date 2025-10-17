#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>

using namespace std;

vector<string> ans;
set<string> existed;


/**
 * 1. exist도 완탐 돌려서 빈칸 채우고 set으로 만든다.
 * 2.
 */

void makeNum(int flag, string s, int idx) {
    if (idx == 8 && flag == 1) {
        existed.insert(s);
        return;
    }

    if (idx == 8 && flag == 0) {
        if (existed.find(s) == existed.end()){
            ans.push_back(s);
        }
        return;
    }

    if (s[idx] != 'X') {
        makeNum(flag, s, idx + 1);
    }
    else {
        for (int i = 0; i <= 9; i++) {
            string temp = s.substr(0, idx) + to_string(i) + s.substr(idx + 1);
            makeNum(flag, temp, idx + 1);
        }
    }
}

void solution(string wanted_number, vector<string> existed_number) {
    for (string existed_num : existed_number) {
        makeNum(1, existed_num, 0);
    }

    makeNum(0, wanted_number, 0);
}

// ====== Local runner (입력/출력만 담당) ======
// 입력 형식 (로컬 테스트용):
// wanted_number
// k
// existed_number[0]
// ...
// existed_number[k-1]
//
// 출력: 가능한 모든 전화번호(사전식), 공백 구분
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string wanted_number;
    if (!getline(cin, wanted_number)) return 0;
    if (wanted_number.empty()) getline(cin, wanted_number); // 빈줄 대비

    int k;
    cin >> k;
    string tmp; getline(cin, tmp); // flush eol

    vector<string> existed_number;
    existed_number.reserve(k);
    for (int i = 0; i < k; ++i) {
        string s; getline(cin, s);
        if (s.empty()) { --i; continue; }
        existed_number.push_back(s);
    }

    solution(wanted_number, existed_number);
    // 출력 형식: 공백 구분 1줄
    for (int i = 0; i < (int)ans.size(); ++i) {
        if (i) cout << ' ';
        cout << ans[i];
    }
    cout << "\n";
    return 0;
}

/*
123-45XX
10
123-450X
123-451X
123-452X
123-453X
123-454X
123-456X
123-457X
123-458X
123-459X
123-4550
 */