// 12919 A와 B 2

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string s;
int found = 0;

void func(string t) {
    // 찾았으면 재귀 진행 x
    if (found == 1) return;

    // t에서 시작해서 s를 찾음
    // 둘의 길이가 같아지면 문자열 비교
    if (s.length() == t.length()) {
        if (s.compare(t) == 0) {
            found = 1;
        }
        return;
    }

    char front = t.at(0); // 맨 앞 문자
    char back = t.at(t.length()-1); // 맨 뒤 문자

    // 앞이 B인 경우, B가 추가 되고 뒤집힌 것
    // 따라서 앞의 B를 제거하고 뒤집음
    if (front == 'B') {
        string str = t;
        str.erase(0,1);
        reverse(str.begin(), str.end());
        func(str);
    }

    // 뒤가 A인 경우 그냥 제거
    if (back == 'A') {
        string str = t;
        str.pop_back();
        func(str);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string t;
    cin >> s >> t;

    func(t);

    cout << found << "\n";

    return 0;
}
