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
int arr[51];
long result = 0;

int main(void) {
    cin >> N;

    for (int u = 0; u < N; u++) {
        cin >> arr[u];
    }

    if (N == 1) {
        cout << arr[0];
        return 0;
    }
    sort(arr, arr + N);

    int u;
    for (u = 0; arr[u] < 0; u++) {
        int mult = arr[u] * arr[u + 1];
        if (mult >= 0) {
            result += mult;
            u++;
        }
        else {
            result += arr[u];
            break;
        }
    }

    for (u = N - 1; arr[u] > 1; u--) {
        int mult = arr[u] * arr[u - 1];
        if (mult > 0) {
            result += mult;
            u--;
        }
        else {
            result += arr[u];
        }
    }

    for (int u = 0; u < N; u++) {
        if (arr[u] == 1) result += arr[u];
    }

    cout << result;
    return 0;
}
