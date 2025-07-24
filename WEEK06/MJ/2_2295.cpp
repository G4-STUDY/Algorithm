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
            two.push_back(arr[u] + arr[v]); // x, y, z 를 더해서 k 를 만들기 위해 x 와 y 를 더한 원소들을 two 에 저장
        }
    }
    sort(two.begin(), two.end());
    for (int u = 0; u < N; u++) {
        for (int v = 0; v < N; v++) {
            if (binary_search(two.begin(), two.end(), arr[v] - arr[u]) && arr[v] > max_value) { // x+y+z=k 인 경우와 k-z=x+z 인 경우가 같음.
                max_value = arr[v];                                                             // k-z=x+z 일때 k값을 max_value에 갱신함.
            }
        }
    }
    cout << max_value;
    return 0;
}
