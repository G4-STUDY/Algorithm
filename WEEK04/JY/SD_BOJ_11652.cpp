// 11652 카드

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    long long temp;
    vector<long long> v;
    for (int i=0; i<n; i++) {
        cin >> temp;
        v.push_back(temp);
    }

    sort(v.begin(), v.end());

    long long cur = v[0];
    long long maxNum = cur;

    int cnt = 1;
    int maxCnt = -1;
    for (int i=1; i<n; i++) {
        if (v[i] == cur) {
            cnt++;
        }
        else {
            if (maxCnt < cnt) {
                maxNum = cur;
                maxCnt = cnt;
            }
            cur = v[i];
            cnt = 1;
        }
    }

    if (maxCnt < cnt) {
        maxNum = cur;
        maxCnt = cnt;
    }

    cout << maxNum << "\n";

    return 0;
}