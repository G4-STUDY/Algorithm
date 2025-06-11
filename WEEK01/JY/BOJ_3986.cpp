// 5. 3986 좋은 단어

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, ans = 0;
    cin >> n;

    string s;
    for (int i=0; i<n; i++) {
        cin >> s;

        stack<char> st;
        for (int j=0; j<s.length(); j++) {
            if (!st.empty() &&
                st.top() == s.at(j)) {
                st.pop();
            }
            else {
                st.push(s.at(j));
            }
        }

        if (st.empty()) ans += 1;
    }

    cout << ans << "\n";

    return 0;
}