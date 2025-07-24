#include <iostream>
#include <set>

using namespace std;

int T, k;
string command;
long long num;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    for (int u = 0; u < T; u++) {
        cin >> k;
        multiset <long long> s;
        int cnt = 0;
        for (int v = 0; v < k; v++) {
            cin >> command >> num;
            if (command == "I") {
                s.insert(num);
                cnt++;
            }
            else if (num == 1) {
                if (cnt == 0) continue;
                s.erase(prev(s.end()));
                cnt--;
            }
            else {
                if (cnt == 0) continue;
                s.erase(s.begin());
                cnt--;
            }
        }
        if (cnt == 0) cout << "EMPTY" << '\n';
        else cout << *prev(s.end()) << ' ' << *s.begin() << '\n';
    }
    return 0;
}