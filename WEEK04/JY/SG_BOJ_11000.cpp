// 11000 강의실 배정

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, s, t;
    cin >> n;

    vector<pair<int, int> > v;
    for (int i=0; i<n; i++) {
        cin >> s >> t;
        v.push_back(make_pair(s,t));
    }

    sort(v.begin(), v.end());

    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i=0; i<n; i++) {
        if (!pq.empty() && pq.top() <= v[i].first) {
            pq.pop();
        }
        pq.push(v[i].second);
    }

    cout << pq.size() << "\n";

    return 0;
}