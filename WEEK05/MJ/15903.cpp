#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;


int n, m;
priority_queue<long long> pq;
int temp;
long long x_card, y_card, hapchae_card;
long long sum;

int main(void) {
    cin >> n >> m;
    for (int u = 0; u < n; u++) {
        cin >> temp;
        pq.push(- temp);
    }
    for (int u = 0; u < m; u++) {
        x_card = - pq.top();
        pq.pop();
        y_card = - pq.top();
        pq.pop();
        hapchae_card = x_card + y_card;
        pq.push(-hapchae_card);
        pq.push(-hapchae_card);
    }
    for (int u = 0; u < n; u++) {
        sum += (-pq.top());
        pq.pop();
    }
    cout << sum;
    return 0;
}
