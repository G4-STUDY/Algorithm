#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

int T, N;
stack <int> days;
int tmp;
int sell_value;
int buy;
long long total_minus;
long long total_plus;
queue <long long> plus_list;
int main(void) {
    cin >> T;
    for (int u = 0; u < T; u++) {
        cin >> N;
        for (int v = 1; v <= N; v++) {
            cin >> tmp;
            days.push(tmp);
        }
        sell_value = 0;
        while (!days.empty()) {
            if (days.top() >= sell_value) {
                total_plus += buy * sell_value - total_minus;
                sell_value = days.top();
                days.pop();
                buy = 0;
                total_minus = 0;
            }
            else {
                buy++;
                total_minus += days.top();
                days.pop();
            }
        }
        total_plus += buy * sell_value - total_minus;
        buy = 0;
        total_minus = 0;

        plus_list.push(total_plus);
        total_plus = 0;
    }
    for (int u = 0; u < T; u++) {
        cout << plus_list.front() << '\n';
        plus_list.pop();
    }
    return 0;
}
