// 1744 수 묶기

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, temp;
    priority_queue<int, vector<int>, greater<int>> negative;
    priority_queue<int> positive;

    cin >> n;

    int ans = 0;
    for (int i=0; i<n; i++) {
        cin >> temp;
        if (temp == 1) {
            ans ++;
        }
        else if (temp > 0) {
            positive.push(temp);
        }
        else {
            negative.push(temp);
        }
    }

    while (!negative.empty()) {
        temp = negative.top();
        negative.pop();

        if (negative.empty()) {
            ans += temp;
            break;
        }

        ans += temp * negative.top();
        negative.pop();
    }

    while (!positive.empty()) {
        int cur = positive.top();
        positive.pop();

        if (positive.empty()) {
            ans += cur;
            break;
        }

        int next = positive.top();
        positive.pop();

        ans += cur * next;
    }

    cout << ans << "\n";

    return 0;
}