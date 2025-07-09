#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;
#define Y first
#define X second
int N;
int x, y;
priority_queue <pair<int, int>> pq;
int from = 1000000001;
int to = 1000000001;
int length, length_sum;
int main(void) {
    cin >> N;
    for (int u = 0; u < N; u++) {
        cin >> x >> y;
        pq.push({ y,x });
    }
    for (int u = 0; u < N; u++) {
        if (pq.top().Y < from) {
            length = to - from;
            length_sum += length;
            from = pq.top().X;
            to = pq.top().Y;

        }
        else if (pq.top().X < from) {
            from = pq.top().X;
        }
        pq.pop();
    }
    length = to - from;
    length_sum += length;
    cout << length_sum;
    return 0;
}
