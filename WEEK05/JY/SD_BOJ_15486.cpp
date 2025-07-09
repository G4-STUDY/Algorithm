// 15486 퇴사 2

#include <iostream>
#include <algorithm>
using namespace std;

long long arr[1600000];
int t[1600000];
int p[1600000];

// 14501 퇴사1과 동일, 자료형만 long long으로 변환
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i=1; i<=n; i++) {
        cin >> t[i] >> p[i];
    }

    for (int i=n; i>0; i--) {
        if (i+t[i]-1 > n) {
            arr[i] = arr[i+1];
        }
        else {
            arr[i] = max(arr[i+1], arr[i+t[i]]+p[i]);
        }
    }

    cout << arr[1] << "\n";

    return 0;
}