#include <bits/stdc++.h>
using namespace std;

int p['Z'-'A'+1];

int find(int a) {
    if (p[a] == -1) return a;
    return p[a] = find(p[a]);
}

bool my_union(int a, int b){
    int x = find(a);
    int y = find(b);

    if (x == y) return false;
    if (x > y) swap(x, y);
    p[x] = y;
    return true;
}


string solution(vector<string> statement) {

    string ans = "";

    for (string sm : statement) {
        int x = sm[0] - 'A';
        int y = sm[1] - 'A';

        if (!my_union(x, y)) {
            ans = sm;
            break;
        }
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


    fill(p, p+'Z'-'A'+1, -1);
    cout << solution(statement) << "\n";
    return 0;
}
