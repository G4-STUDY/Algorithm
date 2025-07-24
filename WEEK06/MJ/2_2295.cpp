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
int arr[1003];
vector <int> two;
int max_value;
long long sum;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int u = 0; u < N; u++) {
        cin >> arr[u];
    }
    sort(arr, arr + N);
    for (int u = 0; u < N; u++) {
        for (int v = u; v < N; v++) {
            two.push_back(arr[u] + arr[v]);
        }
    }
    sort(two.begin(), two.end());
    for (int u = 0; u < N; u++) {
        for (int v = 0; v < N; v++) {
            if (binary_search(two.begin(), two.end(), arr[v] - arr[u]) && arr[v] > max_value) {
                max_value = arr[v];
            }
        }
    }
    cout << max_value;
    return 0;
}
