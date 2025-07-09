#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

long long arr[1000002];
long long result[1000002];
int T, N;

int main(void) {
    cin >> T;
    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 4;
    for (int u = 0; u < T; u++) {
        cin >> N;
        for (int v = 4; v <= N; v++) {
            long long temp = arr[v - 1] + arr[v - 2] + arr[v - 3];
            arr[v] = temp % 1000000009;
        }
        result[u] = arr[N];
    }

    for (int u = 0; u < T; u++) {
        cout << result[u] << '\n';
    }
    return 0;
}
