// 13414 수강신청

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(pair<string, int> a, pair<string, int> b) {
    return a.second < b.second;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int k, l;
    cin >> k >> l;

    // 들어온 순서와 함께 map에 저장
    map<string, int> m;
    string num;
    for (int i = 0; i < l; i++) {
        cin >> num;
        m[num] = i;
    }

    // 들어온 순서대로 정렬
    vector<pair <string, int> > v(m.begin(), m.end());
    sort(v.begin(), v.end(), comp);

    k = min(k, (int)v.size());

    // 성공한 사람 출력
    for (int i = 0; i < k; i++) {
        cout << v[i].first << "\n";
    }

    return 0;
}