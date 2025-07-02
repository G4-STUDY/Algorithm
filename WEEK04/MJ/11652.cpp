#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

int N;

long long arr[100001];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + N);

    int cnt = 1;
    int max_cnt = 0;
    long long max_value = 0;
    for (int i = 0; i < N; i++) {
        if (arr[i] == arr[i + 1]) {
            cnt++;
        }
        else
        {
            cnt = 1;
        }
        if (cnt > max_cnt) {
            max_cnt = cnt;
            max_value = arr[i];
        }
    }

    cout << max_value;

    return 0;
}
