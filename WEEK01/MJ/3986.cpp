#include <stack>
#include <iostream>
using namespace std;

int main(void) {
    int N;
    cin >> N;
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        stack<char> s;
        stack<char> good;
        string str;
        cin >> str;
        if (str.size() % 2) continue;

        for (int j = 0; j < str.size(); j++) {
            s.push(str[j]);
        }
        for (int j = 0; j < str.size(); j++) {
            if (good.empty()) {
                good.push(s.top());
                s.pop();
                j++;
            }
            if (s.top() == good.top()) {
                s.pop();
                good.pop();
            }
            else {
                good.push(s.top());
                s.pop();
            }
        }
        if (good.empty()) cnt++;
    }
    cout << cnt;
}
