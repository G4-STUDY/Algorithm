// 15988 1,2,3 더하기 3

#include <iostream>
using namespace std;

long long arr[1000001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    

    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 4;

    // 자신보다 1, 2, 3 작은 수에 1, 2, 3을 더하면
    // 모든 경우의 수를 구할 수 있음
    for (int i=4; i<1000001; i++) {
        arr[i] = (arr[i-3] + arr[i-2] + arr[i-1]) % 1000000009;
    }

    int t;
    long long n;

    cin >> t;

    while (t--) {
        cin >> n;
        cout << arr[n] << "\n";
    }

    return 0;
}
