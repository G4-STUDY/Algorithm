// 5648 역원소 정렬

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> v;
    string str;
    for (int i=0; i<n; i++) {
        cin >> str;
        reverse(str.begin(), str.end());
        v.push_back(stol(str));
    }

    sort(v.begin(), v.end());

    for (int i=0; i<n; i++) {
        cout << v[i] << "\n";
    }

}