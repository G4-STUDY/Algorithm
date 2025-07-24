// 7785 회사에 있는 사람

#include <iostream>
#include <string>
#include <set>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    string name;
    string log;
    set<string> names;

    // 들어오면 set에 저장, 나가면 뺌
    for (int i = 0; i < n; i++) {
        cin >> name >> log;
        if (log.compare("enter") == 0) {
            names.insert(name);
        }
        else {
            names.erase(name);
        }
    }

    // 내림차순 출력
    vector<string> ans(names.begin(), names.end());
    sort(ans.begin(), ans.end());
    for (int i=ans.size()-1; i>=0; i--) {
        cout << ans[i] << "\n";
    }

    return 0;
}