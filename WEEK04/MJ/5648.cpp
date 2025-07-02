#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

#define Length first
#define Word second

int n;

pair<int, string> s[1000001];
string temp;

int main(void) {
    cin >> n;
    for (int u = 0; u < n; u++) {
        cin >> temp;
        bool flag = false;
        for (int v = 0; v < temp.length(); v++) {
            if ((temp[temp.length() - v - 1] != '0') || flag) {
                flag = true;
                s[u].Word += temp[temp.length() - v - 1];
            }
            s[u].Length = s[u].Word.length();
        }
    }
    sort(s, s + n);
    for (int u = 0; u < n; u++) {
        cout << s[u].Word << '\n';
    }


    return 0;
}
