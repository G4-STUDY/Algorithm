#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

#define Day first
#define Pay second

int N;
int max_pay_each_day[18];
vector <pair<int, int>> counsel_list;
int tempx, tempy;

int main(void) {
    cin >> N;
    for (int u = 1; u <= N; u++) {
        cin >> tempx >> tempy;
        counsel_list.push_back({ tempx, tempy });
    }
    for (int u = 1; u <= N + 1; u++) {
        int temp_max = 0;
        for (int v = 1; v <= 5; v++) {
            if ((u - v) == 0) break;
            if (((u - v) + counsel_list[u - v - 1].Day) <= u) {
                max_pay_each_day[u - v] += counsel_list[u - v - 1].Pay;
                counsel_list[u - v - 1].Pay = 0;
            }
            if (max_pay_each_day[u - v] > temp_max) temp_max = max_pay_each_day[u - v];
        }
        max_pay_each_day[u] = temp_max; 
    }

    cout << max_pay_each_day[N + 1];

    return 0;
}
