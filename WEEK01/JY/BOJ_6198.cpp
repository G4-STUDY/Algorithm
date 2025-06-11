// 2. 6198 옥상 정원 꾸미기

#include <iostream>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio();
    cin.tie(0);

    int n, height;
    long long sum = 0;
    stack<pair<int, int> > st;

    cin >> n;
    cin >> height;

    st.push(make_pair(height,0));
    for (int i = 1; i < n; i++) {
        cin >> height;
        while (!st.empty() && st.top().first <= height) {
            sum += i - st.top().second - 1;
            st.pop();
        }
        st.push(make_pair(height, i));
    }

    height = st.top().second;
    st.pop();
    while (!st.empty()) {
        sum += height - st.top().second;
        st.pop();
    }

    cout << sum << "\n";

    return 0;
}