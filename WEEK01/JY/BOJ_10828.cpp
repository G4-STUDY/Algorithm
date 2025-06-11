// 1. 10828 스택

#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, temp;
    string s;
    stack<int> st;

    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> s;
        if (s.compare("push") == 0) {
            cin >> temp;
            st.push(temp);
        }
        else if (s.compare("pop") == 0) {
            if (!st.empty()) {
                cout << st.top() << "\n";
                st.pop();
            }
            else {
                cout << -1 << "\n";
            }
        }
        else if (s.compare("size") == 0) {
            cout << st.size() << "\n";
        }
        else if (s.compare("empty") == 0) {
            if (!st.empty()) {
                cout << 0 << "\n";
            }
            else {
                cout << 1 << "\n";
            }
        }
        else if (s.compare("top") == 0) {
            if (!st.empty()) {
                cout << st.top() << "\n";
            }
            else {
                cout << -1 << "\n";
            }
        }
    }


    return 0;
}