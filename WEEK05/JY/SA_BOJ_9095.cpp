// 9095 1,2,3 더하기

#include <iostream>
using namespace std;

int arr[12];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, n;
    cin >> t;

    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 4;

    // 자신보다 1, 2, 3 작은 수에 1, 2, 3을 더하면
    // 모든 경우의 수를 구할 수 있음
    for (int i=4; i<=11; i++) {
        arr[i] = arr[i-1] + arr[i-2] + arr[i-3];
    }

    while (t--) {
        cin >>  n;
        cout << arr[n] << "\n";
    }

    return 0;
}