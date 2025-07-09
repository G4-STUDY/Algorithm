// 2170 선 긋기

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<pair<long long, long long> > v;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    long long a, b;
    for (int i=0; i<n; i++) {
        cin >> a >> b;
        v.push_back(make_pair(a, b));
    }
    sort(v.begin(), v.end());

    long long s = v[0].first;
    long long e = v[0].second;
    long long ans = 0;

    // 가장 끝에 있는점과 다음 시작점 비교
    for (int i=0; i<n-1; i++) {
        // 끝나기 전에 시작하는 경우
        if (e >= v[i+1].first) {
            // 지금 시작하는게 더 늦게 끝나면 끝점 갱신
            if (e < v[i+1].second) e = v[i+1].second;
        }
        else {
            // 끝나고 시작함
            // 이전 선의 길이를 더하고 시작점과 끝점 새로 설정
            ans += (e-s);
            s = v[i+1].first; e = v[i+1].second;
        }
    }
    ans += (e-s);

    cout << ans << "\n";

    return 0;
}
