// 1427 소트인사이드

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    cin >> str;

    vector<int> v;
    for (char ch : str) {
        v.push_back(ch-'0');
    }

    sort(v.begin(), v.end());

    for (int i = v.size()-1; i>=0; i--) {
        cout << v[i];
    }

    return 0;
}