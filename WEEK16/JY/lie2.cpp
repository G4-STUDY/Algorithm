#include <bits/stdc++.h>
using namespace std;

/**
 * 위상정렬을 사용하려면
 * 1. 자신이 가리키v는 노드의 집합
 * 2. 자신이 몇번 지목 당했는지 정보가 필요함
 *
 * 1. statement다 돌면서 위에 두개 만듦
 * 2. 다시 statement 돌면서 해당하는거 빼보고 위상정렬 돌려봐
 * 3. 위상정렬 문제 없이 잘 됐어? 그럼 걔가 거짓이 맞는거임
 * 그니까 참을 지우면 모순이 생겨서 위상정렬이 안댐
 */

vector<int> node[26];
int cnt[26];

void init(vector<string> statement) {
    for (int i=0; i<26; i++) {
        node[i].clear();
    }
    fill(cnt, cnt+26, 0);

    for (string s : statement) {
        int a = s[0] - 'A';
        int b = s[1] - 'A';

        node[a].push_back(b);
        cnt[b]++;
    }
}

bool func() {
    queue<int> q;
    for (int i=0; i<26; i++) {
        if (cnt[i] == 0) q.push(i);
    }

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int val : node[cur]) {
            cnt[val]--;

            if (cnt[val] == 0) q.push(val);
        }
    }

    for (int i=0; i<26; i++) {
        if (cnt[i] != 0) return false;
    }
    return true;
}

string solution(vector<string> statement) {
    string ans = "";

    for (string s : statement) {

        init(statement);

        int a = s[0] - 'A';
        int b = s[1] - 'A';

        node[a].erase(remove(node[a].begin(), node[a].end(), b), node[a].end());
        cnt[b]--;

        if (func()) return s;
    }

    return ans;
}

// ====== Local runner (입력/출력만 담당) ======
// 입력 형식 (로컬 테스트용):
// s
// statement[0] statement[1] ... statement[s-1]
// (각 진술은 공백 구분 문자열, 길이 2)
//
// 출력: 거짓 진술 (문자열 1개)
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int s;
    if (!(cin >> s)) return 0;
    vector<string> statement(s);
    for (int i = 0; i < s; ++i) cin >> statement[i];

    cout << solution(statement) << "\n";
    return 0;
}
