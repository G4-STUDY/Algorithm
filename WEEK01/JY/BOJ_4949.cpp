// 6. 4949 균형잡힌 세상

#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string input;
    getline(cin, input);
    while (input.compare(".") != 0) {
        stack<char> st;
        for (int i=0; i<input.length(); i++) {
            if (input.at(i) == '(' || input.at(i) == '[') {
                st.push(input.at(i));
            }
            else if (input.at(i) == ')') {
                if (!st.empty() && st.top() == '(') {
                    st.pop();
                }
                else {
                    st.push(input.at(i));
                    break;
                }
            }
            else if (input.at(i) == ']') {
                if (!st.empty() && st.top() == '[') {
                    st.pop();
                }
                else {
                    st.push(input.at(i));
                    break;
                }
            }
        }

        if (st.empty()) {
            cout << "yes"  << "\n";
        }
        else {
            cout << "no\n" ;
        }

        getline(cin, input);
    }


    return 0;
}