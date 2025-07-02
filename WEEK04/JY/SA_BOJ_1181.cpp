// 1181 단어 정렬

#include <iostream>
#include <algorithm>
#include <set>
#include <string>
#include <vector>
using namespace std;

bool cmp(string a, string b) {
    if (a.length() == b.length()) {
        return a < b;
    }
    return a.length() < b.length();
}

int main() {
    int n;
    cin >> n;

    set<string> s;
    string temp;
    for (int i=0; i<n; i++) {
        cin >> temp;
        s.insert(temp);
    }

    vector<string> v(s.begin(), s.end());

    sort(v.begin(), v.end(), cmp);

    for (string temp : v) {
        cout << temp << "\n";
    }
}